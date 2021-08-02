class Square {
    public:
        int side1, area, perimeter;
        Square(int a) {
            side1 = a;
            area = side1*side1;
            perimeter = 4*side1;
        }
};