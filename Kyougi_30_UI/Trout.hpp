#pragma once






class Trout
{
public:
	Trout();

	void set_score(int number);

	int get_score() const;

	void set_state(int STATE);
	
	int get_state() const;

private:

	int score;//マスに書かれるであろう数値

	int state;//状態、constexprで指定する	


};