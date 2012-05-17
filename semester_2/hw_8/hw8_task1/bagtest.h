#pragma once 

#include <QtTest/QtTest>
#include <sstream>
#include <iostream>
#include <string>
#include "bag.h"

class BagTest : public QObject
{
	Q_OBJECT
private slots:
	void init()
	{
		bag = new Bag<int>;
	}
	
	void cleanup()
	{
		delete bag;
	}

	void testCreate()
	{
		QVERIFY(bag->size() == 0);
	}

	void testAdd()
	{
		bag->add(8);
		QVERIFY(bag->size() != 0);
	}

	void testMultipleAdd()
	{
		int values[] = { 38, 2, 49, 27, 1, 0, 3, 40, 23, 12, 5 };
		for (int i = 0; i < 11; i++)
			bag->add(values[i]);
		QCOMPARE(bag->size(), 11);
	}

	void testHasKey()
	{
		QVERIFY(!bag->hasKey(0));
		bag->add(0);
		QVERIFY(bag->hasKey(0));
		bag->add(10);
		QVERIFY(bag->hasKey(10));
	}

 	void testNumberOf()
	{
		bag->add(10);
		bag->add(5);
		bag->add(15);
		QCOMPARE(bag->numberOf(5), 1);
		bag->add(5);
		QCOMPARE(bag->numberOf(5), 2);
		QCOMPARE(bag->numberOf(3), 0);
	}

	void testRemove()
	{
		int values[] = { 48, 3, 53, 5, 3, 8, 10, 57, 0, 10 };
		for (int i = 0; i < 10; i++)
			bag->add(values[i]);

		bag->remove(5);
		QVERIFY(!bag->hasKey(5));
		bag->remove(10);
		QCOMPARE(bag->numberOf(10), 1);
	}

	void testIteratorBegin()
	{
		int values[] = { 29, 1, 45, 20 };
		for (int i = 0; i < 4; i++)
			bag->add(values[i]);
		Bag<int>::Iterator it = bag->begin();
		QCOMPARE(*it, 1);
	}

	void testIteratorLast()
	{
		int values[] = { 29, 1, 45, 20 };
		for (int i = 0; i < 4; i++)
			bag->add(values[i]);
		Bag<int>::Iterator it = bag->last();
		QCOMPARE(*it, 45);
	}

	void testForwardIteration()
	{
		int values[] = { 48, 3, 53, 5, 3, 8, 10, 57, 0, 10 };
		for (int i = 0; i < 10; i++)
			bag->add(values[i]);

		std::stringstream out;
		std::stringstream out2;
		std::string result("0 3 3 5 8 10 10 48 53 57 ");

		for (Bag<int>::Iterator it = bag->begin(); it != bag->end(); ++it)
			out << *it << ' ';
		QCOMPARE(out.str(), result);
	}

	void testBackwardIteration()
	{
		int values[] = { 48, 3, 53, 5, 3, 8, 10, 57, 0, 10 };
		for (int i = 0; i < 10; i++)
			bag->add(values[i]);

		std::stringstream out;
		std::string result("57 53 48 10 10 8 5 3 3 0 ");

		for (Bag<int>::Iterator it = bag->last(); it != bag->end(); --it)
			out << *it << ' ';
		QCOMPARE(out.str(), result);
	}

	void testIterationWithRepetitionsAtUtterNodes()
	{
		int values[] = { 2, 48, 3, 2 };
		for (int i = 0; i < 4; i++)
			bag->add(values[i]);

		std::stringstream out1;
		std::stringstream out2;
		std::stringstream out3;
		std::stringstream out4;
		std::string result("2 2 3 48 ");

		for (Bag<int>::Iterator it = bag->begin(); it != bag->end(); ++it)
			out1 << *it << ' ';
		QCOMPARE(out1.str(), result);

		result = "48 3 2 2 ";
		for (Bag<int>::Iterator it = bag->last(); it != bag->end(); --it)
			out2 << *it << ' ';
		QCOMPARE(out2.str(), result);
		
		bag->add(48);
		result = "48 " + result;
		for (Bag<int>::Iterator it = bag->last(); it != bag->end(); --it)
			out3 << *it << ' ';
		QCOMPARE(out3.str(), result);

		result = "2 2 3 48 48 ";
		for (Bag<int>::Iterator it = bag->begin(); it != bag->end(); ++it)
			out4 << *it << ' ';
		QCOMPARE(out4.str(), result);
	}	

	void testForwardBackwardIteration()
	{
		int values[] = { 48, 2, 5, 48, 7, 10, 7, 5, 1, 5 };
		for (int i = 0; i < 10; i++)
			bag->add(values[i]);

		std::stringstream out;
		std::string result("7 5 5 7 10 48 10 48 7 ");

		Bag<int>::Iterator it = bag->find(7);
		QVERIFY(bag->find(7) != bag->end());
		out << *it << ' ';
		--it;
		out << *it << ' ';
		--it;
		out << *it << ' ';
		++it; ++it; ++it;
		out << *it << ' ';
		++it;
		out << *it << ' ';
		++it;
		out << *it << ' ';
		--it;
		out << *it << ' ';
		++it;
		out << *it << ' ';
		--it; --it;
		out << *it << ' ';
		QCOMPARE(out.str(), result);
	}

	void testAddBag()
	{
		int values1[] = { 38, 58, 2, 5, 5, 0, 10 };
		int values2[] = { 10, 5, 8, 72, 3, 10, 10 };
		Bag<int> sec;

		for (int i = 0; i < 7; i++)
		{
			bag->add(values1[i]);
			sec.add(values2[i]);
		}

		bag->add(sec);

		std::stringstream out;
		std::string result("0 2 3 5 5 5 8 10 10 10 10 38 58 72 ");
		for (Bag<int>::Iterator it = bag->begin(); it != bag->end(); ++it)
			out << *it << ' ';

		QCOMPARE(out.str(), result);
	}

	void testUnite()
	{
		int values1[] = { 38, 58, 2, 5, 5, 0, 10 };
		int values2[] = { 10, 5, 8, 72, 3, 10, 10 };
		Bag<int> sec;

		for (int i = 0; i < 7; i++)
		{
			bag->add(values1[i]);
			sec.add(values2[i]);
		}

		Bag<int> bagUnion = bag->unite(sec);

		std::stringstream out;
		std::string result("0 2 3 5 5 5 8 10 10 10 10 38 58 72 ");
		for (Bag<int>::Iterator it = bagUnion.begin(); 
				it != bagUnion.end(); ++it)
			out << *it << ' ';

		QCOMPARE(out.str(), result);
	}

	void testIntersect()
	{
		int values1[] = { 38, 58, 2, 5, 5, 0, 10 };
		int values2[] = { 10, 5, 8, 72, 3, 10, 10 };
		Bag<int> sec;

		for (int i = 0; i < 7; i++)
		{
			bag->add(values1[i]);
			sec.add(values2[i]);
		}

		Bag<int> intersection = bag->intersect(sec);

		std::stringstream out;
		std::string result("5 10 ");
		for (Bag<int>::Iterator it = intersection.begin(); 
				it != intersection.end(); ++it)
			out << *it << ' ';

		QCOMPARE(out.str(), result);
	}

private:
	Bag<int>* bag;
};

