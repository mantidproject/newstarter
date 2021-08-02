class Circle {
    public:
        int radius, area, perimeter;
        Circle(int a) {
            radius = a;
            area = radius*radius*3.14;
            perimeter = 2*radius*3.14;
        }
};