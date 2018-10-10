#ifndef TREE_HPP
#define TREE_HPP

struct GALAZ{
	int war;
	GALAZ *lewy;
	GALAZ *prawy;
};

class Tree{
private:
	GALAZ *korzen;
	void dodaj(int, GALAZ *);
	void wyswietl(GALAZ *);
	void czysc(GALAZ *);

public:
	Tree();
	Tree(int);
	~Tree();

	void dodaj(int);
	void wyswietl();
};

#endif