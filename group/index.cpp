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

class Medico
{
    string CRM;
    string Especialidade;

public:
    string Nome;

    Medico(string _Nome, string _CRM, string _Especialidade)
    {
        this->Nome = _Nome;
        this->setCRM(_CRM);
        this->setEspecialidade(_Especialidade);
    }

    string getCRM()
    {
        return this->CRM;
    }

    void setCRM(string _CRM)
    {

        this->CRM = _CRM;
    }

    string getEspecialidade()
    {
        return this->Especialidade;
    }

    void setEspecialidade(string _Especialidade)
    {

        this->Especialidade = _Especialidade;
    }
};

int main()
{
    std::cout << "Hello World!";
    return 0;
}