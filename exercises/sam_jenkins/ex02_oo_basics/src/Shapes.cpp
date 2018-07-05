#include <string>
class Shapes {
public:
	Shapes::Shapes() :type("undefined"), sides(0) {};
	std::string getType()
	{
		return type;
	}
	int getSides()
	{
		return sides;
	}
	
	
protected:
	std::string type;
	int sides;
};