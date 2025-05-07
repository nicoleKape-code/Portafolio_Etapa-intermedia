class Criaturas{
  private:
    string name, type, size, align;
    float cr;
    int ac, hp;
    bool vivo;
  public:
    Criaturas(string, float, string, string, int, int, string);
    string getName();
    string getType();
    string getSize();
    string getAlign();
    float getCr();
    int getAc();
    int getHp();
    bool getVivo();
    void setVivo(bool);
    void printInfo();
};