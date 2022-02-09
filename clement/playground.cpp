#include "playground.hpp"

Playground::Playground(int windowWidth, int windowHeight, int squareSize){
    this->squareSize = squareSize;
    this->numbOfCol = windowWidth/squareSize;
    this->numbOfRow = windowHeight/squareSize;
}

int Playground::GetNumbOfCol(){
    return numbOfCol;
}

int Playground::GetNumbOfRow(){
    return numbOfRow;
}

int Playground::GetSquareSize(){
    return squareSize;
}
