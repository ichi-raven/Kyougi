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

	int score;//�}�X�ɏ������ł��낤���l

	int state;//��ԁAconstexpr�Ŏw�肷��	


};