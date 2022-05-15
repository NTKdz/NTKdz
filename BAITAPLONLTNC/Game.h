#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Position.h"
#include "SDL.h"
#include <SDL_ttf.h>
enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_OVER = 8 | GAME_STOP,
    GAME_PAUSE
};

enum CellType {
    CELL_EMPTY = 0, CELL_SNAKE, CELL_MOUSE, CELL_OFF_BOARD
};

class Game
{
public:
	const int width;
	const int height;

private:
    std::vector< std::vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score=0;
    std::queue<Direction> inputQueue;
    Direction currentDirection;
    Position mousePosition;

public:
    Game(int _width, int _height);
    ~Game();
    bool mouseEated=false;
	//////////////////////////////////////
    bool isGameRunning() const { return status == GAME_RUNNING; }
    bool isGameOver() const { return status == GAME_OVER; }
    void processUserInput(Direction direction);
    void nextStep();
    const std::vector< std::vector<CellType> >& getSquares() const { return squares; }
    CellType getCellType(Position p) const;
    void setGameStatus(GameStatus status);

    std::vector<Position> getSnakePositions() const;
    Position getMousePosition() const { return mousePosition; }
    int getScore() { return score; }
    bool canChange(Direction current, Direction next) const;

    void snakeMoveTo(Position position);
    void snakeLeave(Position position);
    void playagain(bool&quit);
private:
    bool running=true;
	void addMouse();
	void setCellType(Position pos, CellType cellType);
	/////////////////////////////////
	void drawText(int score, int lives);
	std::string createText(int score, int lives);
};

#endif // GAMEGROUND_H
