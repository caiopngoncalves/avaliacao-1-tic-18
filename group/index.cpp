#include <iostream>
#include <string>

using namespace std;

class Paciente
{

    string CPF;
    string DtNascimento;

public:
    string Nome;

    Paciente(string _Nome, string _CPF, string _DtNascimento)
    {
        this->Nome = _Nome;
        this->setCPF(_CPF);
        this->setDtNascimento(_DtNascimento);
    }

    string getCPF()
    {
        return this->CPF;
    }

    void setCPF(string _CPF)
    {
        this->CPF = _CPF;
    }

    string getDtNascimento()
    {
        return this->DtNascimento;
    }

    void setDtNascimento(string _DtNascimento)
    {

        this->DtNascimento = _DtNascimento;
    }
};

int main()
{
    std::cout << "Hello World!";
    return 0;
}