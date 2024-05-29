//
// Created by gfl56326 on 29/05/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape {
private:
    double side1;
public:
    Triangle(double side);

    std::string getType() override;
    double calculateArea() override;
    int getNumberOfSides() override;
};

#endif //TRIANGLE_H
