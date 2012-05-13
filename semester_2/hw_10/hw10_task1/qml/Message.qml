import QtQuick 1.0

Rectangle {
	id: mess

	property alias text: msg.text
	property alias winner: msg.winner
	property alias textColor: msg.color

	property alias newGameColor: newGameButton.color
	property alias closeColor: closeButton.color

	property int margin: 5
	property int buttonHeight: newGameButton.height
	height: msg.height + buttonHeight + margin * 2

	property bool shown: false

	signal newGame()
	signal exit()

	TextEdit {
		id: msg

		width: parent.width
		anchors.top: parent.top
		anchors.horizontalCenter: parent.horizontalCenter

		verticalAlignment: TextEdit.AlignVCenter
		horizontalAlignment: TextEdit.AlignHCenter
		readOnly: true
		wrapMode: TextEdit.Wrap

		property string winner: "X"
		text: "The game is over.\n" + winner +
				" wins.\nWould you like to start a new game?"
	}

	Button {
		id: newGameButton

		color: "lightblue"
		border.color: "blue"
		border.width: 2
		radius: 4
		text: "New Game"

		anchors.right: closeButton.left
		anchors.rightMargin: parent.margin
		anchors.bottom: parent.bottom
		anchors.bottomMargin: parent.margin

		onClick: newGame()
	}

	Button {
		id: closeButton

		color: "red"
		border.color: "crimson"
		border.width: 2
		radius: 4
		text: "Exit"

		anchors.right: parent.right
		anchors.rightMargin: parent.margin
		anchors.bottom: parent.bottom
		anchors.bottomMargin: parent.margin

		onClick: exit()
	}

	states: State {
		name: "invisible"
		when: !shown

		PropertyChanges { 
			target: mess
			color: "transparent"
			textColor: "transparent"
			border.color: "transparent"
		}
		PropertyChanges {
			target: newGameButton
			color: "transparent"
			border.color: "transparent"
			textColor: "transparent"
			onClick: {}
		}
		PropertyChanges {
			target: closeButton
			color: "transparent"
			border.color: "transparent"
			textColor: "transparent"
			onClick: {}
		}
	}
}
