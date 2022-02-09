#ifndef PLAYGROUND_HPP
#define PLAYGROUND_HPP

class Playground{
    public:
        Playground(int windowWidth, int windowHeight, int squareSize);

        ~Playground();

        int GetNumbOfCol();
        int GetNumbOfRow();
        int GetSquareSize();

    private:
        int numbOfRow;
        int numbOfCol;
        int squareSize;
};

#endif