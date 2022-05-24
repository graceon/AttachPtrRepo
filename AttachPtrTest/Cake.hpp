class Cake
{
public:
	int x;
	Cake();
	Cake(int);
	~Cake();

private:

};

class AppleCake:public Cake
{
public:
	int y;
	AppleCake();
	AppleCake(int);
	~AppleCake();

private:

};

