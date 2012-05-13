import QtQuick 1.0

Rectangle {
	id: field

	property int side: 3
	property int nextStep: 1
	property int cellSize: 50
	property int spacing: 1
	property int steps: 0

	color: "black"
	width: (cellSize + spacing) * side - spacing
	height: (cellSize + spacing) * side - spacing

	Grid {
		id: grid
		anchors.centerIn: parent

		rows: parent.side; columns: parent.side
		spacing: parent.spacing

		Repeater {
			id: cells
			model: field.side * field.side

			Image {
				property bool isUnset: true
				property int type: 0

				width: field.cellSize; height: field.cellSize
				source: "unsetImage.png"

				MouseArea {
					id: area
					anchors.fill: parent

					onClicked: {
						if (isUnset)
						{
							type = field.nextStep
							if (field.nextStep == 1)
							{
								source = "xImage.png"
								field.nextStep = 2
							}
							else
							{
								source = "oImage.png"
								field.nextStep = 1
							}

							isUnset = false
							field.steps++

							if (cells.isGameOver(index))
								field.gameOver(cells.itemAt(index).type)

							else if (field.steps == field.side * field.side)
								field.gameOver(0)
						}
					}
				}
			}

			function isGameOver(index) 
			{
				return checkRow(index) || checkColumn(index)
						|| index % (field.side + 1) == 0 && checkMainDiag()
						|| index % (field.side - 1) == 0 && index != 0
							&& index != field.side * field.side - 1 && checkSideDiag();
			}

			function checkColumn(index) 
			{
				var side = field.side;
				
				for (var i = index % side + side; i < side * side; i += side)
					if (cells.itemAt(i).type == 0 
							|| cells.itemAt(i).type != cells.itemAt(index % side).type)
						return false;
						
				return true;
			}

			function checkRow(index) 
			{	
				var side = field.side;
				var row = Math.floor(index / side);

				for (var i = row * side + 1; i < (row + 1) * side; i++)
					if (cells.itemAt(i).type == 0
							|| cells.itemAt(i).type != cells.itemAt(row * side).type)
						return false;

				return true;
			}

			function checkMainDiag()
			{
				var side = field.side;

				for (var i = side + 1; i < side * side; i += side + 1)
					if (cells.itemAt(i).type == 0
							|| cells.itemAt(i).type != cells.itemAt(0).type)
						return false;

				return true;
			}

			function checkSideDiag()
			{
				var side = field.side;

				for (var i = 2 * side - 2; i < side * side - 1; i += side - 1)
					if (cells.itemAt(i).type == 0
							|| cells.itemAt(i).type != cells.itemAt(side - 1).type)
						return false;

				return true;
			}
		}
	}

	function gameOver(winner)
	{
		for (var i = 0; i < side * side; i++)
			cells.itemAt(i).isUnset = false

		switch (winner)
		{
			case 0: message.winner = "No one";
					break;
			case 1: message.winner = "X";
					break;
			case 2: message.winner = "O";
		}
		message.shown = true
	}

	Message {
		id: message

		color: "lightgrey"
		border.color: "darkgrey"
		border.width: 2

		anchors.centerIn: parent
		width: grid.width >= 300 ? grid.width * (3/4) : grid.width - 2 * margin
		radius: 6

		onNewGame: startNewGame()
		onExit: Qt.quit()
	}

	function startNewGame()
	{
		steps = 0
		nextStep = 1
		message.shown = false

		for (var i = 0; i < side * side; i++)
		{
			cells.itemAt(i).isUnset = true
			cells.itemAt(i).source = "unsetImage.png"
			cells.itemAt(i).type = 0
		}
	}
}

