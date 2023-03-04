class rational {
private:
    int a, b;
public:
    rational();
    rational(int a1, int b1);
    void set(int a1, int b1);
    void show();
    rational operator + (rational r);
    friend rational operator - (rational r1, rational r2);
    void operator ++ ();
    bool operator == (rational r);
    bool operator > (rational r);
    void operator = (rational r);
};