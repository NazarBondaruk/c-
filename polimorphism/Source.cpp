#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() {}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Print() {
		cout << "x: " << this->x << " ";
		cout << "y: " << this->y << "\n";
	}
};


class Size {
	int width, height;
public:
	Size() {}
	Size(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void Print() {
		cout << "width: " << this->width << " ";
		cout << "height :" << this->height << "\n";
	}
};


class Graphics {
public:
	void DrawPolygon(string color, string line, Point* points) {
		cout << "Draw Polygon!\n";
	}

	void DrawRectangle(string color, string line, Point* location, Size* size) {
		cout << "Draw Rectangle!\n";
	}

	void DrawTriangle(string color, string line, Point* points) {
		cout << "Draw Triangle!\n";
	}

	void DrawCircle(string color, string line, Point* center, double radius) {
		cout << "Draw Circle!\n";
	}

};



class LineStyle
{
public:
	virtual string getLineStyle() {
		return "Solid";
	}
};


class DashLine : public LineStyle {
public:
	string getLineStyle() override {
		return "DashLine";
	}
};

class DotLine : public LineStyle
{
public:
	string getLineStyle() override {
		return "DotLine";
	}
};

class DashDotLine : public LineStyle {
public:
	string getLineStyle() override {
		return "Dash-DotLine";
	}
};




class Shape
{
protected:
	Graphics* graphics = nullptr;
	string line;
	string color;
public:


	virtual void Draw(string color, LineStyle* lineStyle) {
		this->color = color;
		this->graphics = new Graphics();
		this->line = lineStyle->getLineStyle();
	}


	virtual void PrintShapeInfo() {
		cout << this->color << "\n";
		cout << this->line << "\n";
	}
};


class Polygon : public Shape
{
	// Создать массив точек
	Point* points;

public:


	Polygon() {
		points = new Point[5]
		{
			 Point(10, 10),
			 Point(10, 100),
			 Point(50, 65),
			 Point(100, 100),
			 Point(85, 40)
		};
	}


	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);

		// Нарисовать фигуру.            
		this->graphics->DrawPolygon(color, line, points);

		this->PrintShapeInfo();
	}


	void PrintShapeInfo() override {

		Shape::PrintShapeInfo();

		cout << "Coords: \n";
		for (int i = 0; i < 5; i++)
		{
			this->points[i].Print();
		}
	}


};


class Rectangle : public Shape
{


	Point* location = new Point(10, 20);
	Size* size = new Size(100, 200);

public:
	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);

		// Нарисовать фигуру.
		this->graphics->DrawRectangle(color, line, location, size);

		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {

		Shape::PrintShapeInfo();
		location->Print();
		size->Print();
	}
};



class Triangle : public Shape
{
	// Создать массив точек
	Point* points;
public:

	Triangle() {
		points = new Point[3]
		{
			 Point(50, 50),
			 Point(50, 200),
			 Point(200, 200)
		};
	}
	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);

		// Нарисовать фигуру.            
		this->graphics->DrawTriangle(color, line, points);

		this->PrintShapeInfo();
	}


	void PrintShapeInfo() override {

		Shape::PrintShapeInfo();

		cout << "Coords: \n";
		for (int i = 0; i < 3; i++) {
			this->points[i].Print();
		}
	}
};

class Circle : public Shape {
	Point* center;
	double radius;
public:
	Circle() {
		center = new Point(50, 0);
		radius = 50.0;
	}

	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);

		this->graphics->DrawCircle(color, line, center, radius);
		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {
		Shape::PrintShapeInfo();

		cout << "Center: \n"; 
		center->Print();
		cout << "Radius: " << radius << endl;
	}

	~Circle() {
		delete center;
	}
};


class Context {
public:
	void Draw(Shape* shape, LineStyle* lineStyle, string color)
	{
		shape->Draw(color, lineStyle);
	}
};








int main() {

	Context context;

	context.Draw(new Rectangle(), new DashLine(), "Red");
	cout << string(100, '-') << "\n";
	context.Draw(new Triangle(), new DotLine(), "Green");
	cout << string(100, '-') << "\n";
	context.Draw(new Polygon(), new DotLine(), "Blue");
	cout << string(100, '-') << "\n";
	context.Draw(new Circle(), new DashDotLine(), "Black");


	return 0;
}
