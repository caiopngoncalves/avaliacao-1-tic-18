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

class Consulta
{
    Paciente *paciente;
    Medico *medico;
    bool realizada;
    string dataHora;
    string duracao;
    string convenio;

public:
    Consulta(Paciente *_Paciente, Medico *_Medico, bool _Realizada, string _DataHora, string _Duracao, string _Convenio)
    {
        this->paciente = _Paciente;
        this->medico = _Medico;
        this->realizada = _Realizada;
        this->dataHora = _DataHora;
        this->duracao = _Duracao;
        this->convenio = _Convenio;
    }

    Paciente *getPaciente()
    {
        return this->paciente;
    }

    void setPaciente(Paciente *_Paciente)
    {

        this->paciente = _Paciente;
    }

    Medico *getMedico()
    {
        return this->medico;
    }

    void setMedico(Medico *_Medico)
    {

        this->medico = _Medico;
    }

    bool getRealizada()
    {
        return this->realizada;
    }

    void setRealizada(bool _Realizada)
    {

        this->realizada = _Realizada;
    }

    string getDataHora()
    {
        return this->dataHora;
    }

    void setDataHora(string _DataHora)
    {
        this->dataHora = _DataHora;
    }

    string getDuracao()
    {
        return this->duracao;
    }

    void setDuracao(string _Duracao)
    {
        this->duracao = _Duracao;
    }

    string getConvenio()
    {
        return this->convenio;
    }

    void setConvenio(string _Convenio)
    {
        this->convenio = _Convenio;
    }
};

int main()
{
    std::cout << "Hello World!";
    return 0;
}