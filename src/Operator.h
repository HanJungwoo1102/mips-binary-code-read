class Operator {
	protected:
		char* name;
		Operator(char* name){ this->name = name; };
	public:
		char* getName(){ return this->name; };
};

class AddOperator : public Operator {
	public:
		AddOperator();
};
