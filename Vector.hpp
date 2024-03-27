#ifndef VECTOR_HPP
#define VECTOR_HPP

class vector_2d
{
public:
	vector_2d() {};
	vector_2d(int x, int y);
	virtual ~vector_2d();

	int    get_x() const;
	int    get_y() const;
	virtual double length() const;
	virtual void   print() const;

protected:
	int x_;
	int y_;
private:

};

vector_2d::vector_2d(int x, int y)
{
	std::cout << "vector_2d::ctr\n";
	x_ = x;
	y_ = y;
}

vector_2d::~vector_2d()
{
	std::cout << "vector_2d::dtr\n";
}

int    vector_2d::get_x() const
{
	std::cout << "vector_2d::get_x\n";
	return x_;
}

int    vector_2d::get_y() const
{
	std::cout << "vector_2d::get_y\n";

	return y_;
}

double vector_2d::length() const
{
	std::cout << "vector_2d::length\n";

	return std::sqrt(x_ * x_ + y_ * y_);
}

void   vector_2d::print() const
{
	std::cout << "x: " << x_ << " y: " << y_ << " length: " << length() << "\n";
}


//final
class vector_3d : public vector_2d
{
public:
	vector_3d() {};
	vector_3d(int x, int y, int z);
	~vector_3d();

	int    get_z() const;
	double length() const;
	void   print() const;
protected:
	int z_;
};

vector_3d::vector_3d(int x, int y, int z)
	: vector_2d(x, y)
	//, z_(z)
{
	std::cout << "vector_3d::ctr\n";
	z_ = z;
}

vector_3d::~vector_3d()
{
	std::cout << "vector_3d::dtr\n";
}

int    vector_3d::get_z() const
{
	std::cout << "vector_3d::get_z\n";
	return z_;
}

double vector_3d::length() const
{
	std::cout << "vector_3d::length\n";
	return std::sqrt(x_ * x_ + y_ * y_ + z_ + z_);
}

void   vector_3d::print() const
{
	std::cout << "vector_3d::print\n";
	std::cout << "x: " << x_ << " y: " << y_ << " z: " << z_ << " length: " << length() << "\n";
}
#endif // !VECTOR_HPP
