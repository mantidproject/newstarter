class Rectangle {
    public:
        int side1, area, perimeter;
        Rectangle(int a) {
            side1 = a;
            area = side1;
            perimeter = 2*side1+2;
        }
};