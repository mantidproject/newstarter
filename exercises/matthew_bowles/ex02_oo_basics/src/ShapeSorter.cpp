#include "ShapeSorter.h"

using namespace std;

ShapeSorter::ShapeSorter()
{
}

void ShapeSorter::matchType(string type, vector<Shape*> shapes)
{
	vector<Shape*>::iterator iter = shapes.begin();
	while (iter != shapes.end())
	{
		printf("matching... \n");
		if (type.compare((*iter)->getType()) != 0)
		{
			cout << "no match between " << (*iter)->getType() << " and " << type << endl;
			iter = shapes.erase(iter);
		}
		else
		{
			printf("match \n");
			++iter;
		}
			
		
	}
	printShapes(shapes);
}

void ShapeSorter::printShapes(vector<Shape*> &shapes)
{
	vector<Shape*>::const_iterator iter = shapes.begin();
	while (iter != shapes.end())
	{
		(*iter)->print();
		++iter;
	}
	getchar();
}

ShapeSorter::~ShapeSorter()
{
}

