#pragma once

#include <QtTest/QtTest>
#include <QString>
#include <sstream>
#include <iostream>
#include <string>
#include "bubblesorter.h"

class SorterTest : public QObject
{
	Q_OBJECT
private slots:
	void testIntSort()
	{
		int array[] = { 38, 4, 187, 3, 690, 2, 5, 12, 56, 398 };

		IntComparator comparator;
		BubbleSorter<int> intSorter;
		intSorter.sort(array, 10, comparator);

		std::stringstream out;
		std::string result("2 3 4 5 12 38 56 187 398 690 ");
		for (int i = 0; i < 10; i++)
			out << array[i] << ' ';

		QCOMPARE(out.str(), result);
	}

	void testQStringSensitiveSort()
	{
		QString array[] = { "apple", "Dog", "balloon", "dog"
				, "melon", "APPLE" };

		QStringComparator comparator;
		BubbleSorter<QString> sorter;
		sorter.sort(array, 6, comparator);

		std::stringstream out;
		std::string result("APPLE Dog apple balloon dog melon ");
		for (int i = 0; i < 6; i++)
			out << array[i].toStdString() << ' ';

		QCOMPARE(out.str(), result);
	}

	void testQStringInsensitiveSort()
	{
		QString array[] = { "apple", "Dog", "balloon", "dog"
				, "melon", "APPLE" };

		QStringComparator comparator(Qt::CaseInsensitive);
		BubbleSorter<QString> sorter;
		sorter.sort(array, 6, comparator);

		std::stringstream out;
		std::string result("apple APPLE balloon Dog dog melon ");
		for (int i = 0; i < 6; i++)
			out << array[i].toStdString() << ' ';

		QCOMPARE(out.str(), result);
	}

private:
	class IntComparator
	{
	public:
		int operator() (int const a, int const b) const
		{ return a - b; }
	};

	class QStringComparator
	{
	public:
		QStringComparator(Qt::CaseSensitivity cs = Qt::CaseSensitive)
			: sensitivity(cs)
		{}
		int operator() (QString const &a, QString const &b) const
		{ return a.compare(b, sensitivity); }
	private:
		Qt::CaseSensitivity sensitivity;
	};
};
