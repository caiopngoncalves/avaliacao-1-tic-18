#include <iostream>
#include <string>
#include <vector>

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
class GerenciadorPacientes
{
private:
    vector<Paciente> pacientes;

public:
    void incluirPaciente()
    {
        string cpf, nome, dtNascimento;
        cout << "CPF: ";
        cin >> cpf;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Data de Nascimento: ";
        cin >> dtNascimento;

        pacientes.push_back(Paciente(nome, cpf, dtNascimento));
    }

    void excluirPaciente()
    {
        string cpf;
        cout << "Informe o CPF do paciente a ser excluído: ";
        cin >> cpf;

        for (auto it = pacientes.begin(); it != pacientes.end(); ++it)
        {
            if (it->getCPF() == cpf)
            {
                pacientes.erase(it);
                cout << "Paciente excluído com sucesso.\n";
                return;
            }
        }

        cout << "Paciente nao encontrado.\n";
    }

    void alterarPaciente()
    {
        string cpf, data;
        cout << "Informe o CPF do paciente a ser alterado: ";
        cin >> cpf;

        for (auto &paciente : pacientes)
        {
            if (paciente.getCPF() == cpf)
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, paciente.Nome);
                cout << "Nova Data de Nascimento: ";
                cin >> data;
                paciente.setDtNascimento(data);
                cout << "Paciente alterado com sucesso.\n";
                return;
            }
        }

        cout << "Paciente nao encontrado.\n";
    }

    void listarPacientes()
    {
        cout << "Lista de Pacientes:\n";
        for (auto paciente : pacientes)
        {
            cout << "CPF: " << paciente.getCPF() << ", Nome: " << paciente.Nome << ", Data de Nascimento: " << paciente.getDtNascimento() << endl;
        }
    }

    void localizarPaciente()
    {
        string cpf;
        cout << "Informe o CPF do paciente: ";
        cin >> cpf;

        for (auto &paciente : pacientes)
        {
            if (paciente.getCPF() == cpf)
            {
                cout << "Paciente encontrado:\n";
                cout << "CPF: " << paciente.getCPF() << ", Nome: " << paciente.Nome << ", Data de Nascimento: " << paciente.getDtNascimento() << endl;
                return;
            }
        }

        cout << "Paciente nao encontrado.\n";
    }

    bool pacienteExiste(string cpf)
    {
        for (auto &paciente : pacientes)
        {
            if (paciente.getCPF() == cpf)
            {
                return true;
            }
        }
        return false;
    }

    Paciente *getPacientePorCPF(string cpf)
    {
        for (auto &paciente : pacientes)
        {
            if (paciente.getCPF() == cpf)
            {
                return &paciente;
            }
        }
        return nullptr;
    }
};

class GerenciadorMedicos
{
private:
    vector<Medico> medicos;

public:
    void incluirMedico()
    {
        string crm, nome, especialidade;
        cout << "CRM: ";
        cin >> crm;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Especialidade: ";
        getline(cin, especialidade);

        medicos.push_back(Medico(nome, crm, especialidade));
    }

    void excluirMedico()
    {
        string crm;
        cout << "Informe o CRM do medico a ser excluido: ";
        cin >> crm;

        for (auto it = medicos.begin(); it != medicos.end(); ++it)
        {
            if (it->getCRM() == crm)
            {
                medicos.erase(it);
                cout << "Medico excluido com sucesso.\n";
                return;
            }
        }

        cout << "Medico nao encontrado.\n";
    }

    void alterarMedico()
    {
        string crm, especialidade;
        cout << "Informe o CRM do medico a ser alterado: ";
        cin >> crm;

        for (auto &medico : medicos)
        {
            if (medico.getCRM() == crm)
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, medico.Nome);
                cout << "Nova Especialidade: ";
                getline(cin, especialidade);
                medico.setEspecialidade(especialidade);
                cout << "Medico alterado com sucesso.\n";
                return;
            }
        }

        cout << "Medico nao encontrado.\n";
    }

    void listarMedicos()
    {
        cout << "Lista de Medicos:\n";
        for (auto &medico : medicos)
        {
            cout << "CRM: " << medico.getCRM() << ", Nome: " << medico.Nome << ", Especialidade: " << medico.getEspecialidade() << endl;
        }
    }

    void localizarMedico()
    {
        string crm;
        cout << "Informe o CRM do medico: ";
        cin >> crm;

        for (auto &medico : medicos)
        {
            if (medico.getCRM() == crm)
            {
                cout << "Medico encontrado:\n";
                cout << "CRM: " << medico.getCRM() << ", Nome: " << medico.Nome << ", Especialidade: " << medico.getEspecialidade() << endl;
                return;
            }
        }
        cout << "Medico nao encontrado.\n";
    }

    bool medicoExiste(string crm)
    {
        for (auto &medico : medicos)
        {
            if (medico.getCRM() == crm)
            {
                return true;
            }
        }
        return false;
    }

    Medico *getMedicoPorCRM(string crm)
    {
        for (auto &medico : medicos)
        {
            if (medico.getCRM() == crm)
            {
                return &medico;
            }
        }
        return nullptr;
    }
};
class GerenciadorConsultas
{
private:
    vector<Consulta> consultas;

public:
    void incluirConsulta(GerenciadorPacientes gerenciadorPacientes, GerenciadorMedicos gerenciadorMedicos)
    {
        string cpf, crm, data, hora, duracao, convenio;
        cout << "CPF do paciente: ";
        cin >> cpf;

        if (!gerenciadorPacientes.pacienteExiste(cpf))
        {
            cout << "Paciente nao encontrado.\n";
            return;
        }

        cout << "CRM do medico: ";
        cin >> crm;

        if (!gerenciadorMedicos.medicoExiste(crm))
        {
            cout << "Medico nao encontrado.\n";
            return;
        }

        Paciente *paciente = gerenciadorPacientes.getPacientePorCPF(cpf);
        Medico *medico = gerenciadorMedicos.getMedicoPorCRM(crm);

        cout << "Data da consulta: ";
        cin >> data;
        cout << "Hora da consulta: ";
        cin >> hora;
        cout << "Duracao da consulta: ";
        cin >> duracao;
        cout << "Convenio: ";
        cin >> convenio;

        consultas.push_back(Consulta(paciente, medico, false, data + " " + hora, duracao, convenio));
    }

    void excluirConsulta(GerenciadorMedicos gerenciadorMedicos)
    {
        string crm;
        cout << "CRM do medico: ";
        cin >> crm;

        if (!gerenciadorMedicos.medicoExiste(crm))
        {
            cout << "Medico nao encontrado.\n";
            return;
        }

        Medico *medico = gerenciadorMedicos.getMedicoPorCRM(crm);

        cout << "Pacientes com consultas do medico " << medico->Nome << ":\n";
        for (int i = 0; i < consultas.size(); ++i)
        {
            if (consultas[i].getMedico() == medico)
            {
                cout << "CPF: " << consultas[i].getPaciente()->getCPF() << ", Nome: " << consultas[i].getPaciente()->Nome << endl;
            }
        }

        string cpf;
        cout << "Informe o CPF do paciente a ser excluido: ";
        cin >> cpf;

        for (auto it = consultas.begin(); it != consultas.end(); ++it)
        {
            if (it->getPaciente()->getCPF() == cpf && it->getMedico() == medico)
            {
                if (!it->getRealizada())
                {
                    consultas.erase(it);
                    cout << "Consulta excluida com sucesso.\n";
                    return;
                }
                else
                {
                    cout << "A consulta nao pode ser excluida porque ja foi realizada.\n";
                    return;
                }
            }
        }

        cout << "Consulta nao encontrada.\n";
    }

    void alterarConsulta(GerenciadorMedicos gerenciadorMedicos)
    {
        string crm;
        cout << "CRM do medico: ";
        cin >> crm;

        if (!gerenciadorMedicos.medicoExiste(crm))
        {
            cout << "Medico nao encontrado.\n";
            return;
        }

        Medico *medico = gerenciadorMedicos.getMedicoPorCRM(crm);

        cout << "Pacientes com consultas do medico " << medico->Nome << ":\n";
        for (int i = 0; i < consultas.size(); ++i)
        {
            if (consultas[i].getMedico() == medico)
            {
                Paciente *paciente = consultas[i].getPaciente();
                if (paciente)
                {
                    cout << /* "CPF: " << paciente->getCPF() << */ ", Nome: " << paciente->Nome << endl;
                }
                else
                {
                    cout << "Erro: Paciente nulo na consulta.\n";
                }
            }
        }

        string cpf;
        cout << "Informe o CPF do paciente: ";
        cin >> cpf;

        for (auto &consulta : consultas)
        {
            if (consulta.getPaciente()->getCPF() == cpf && consulta.getMedico() == medico)
            {
                char opcao;
                cout << "A consulta foi realizada? (S/N): ";
                cin >> opcao;

                if (opcao == 'S' || opcao == 's')
                {
                    consulta.setRealizada(true);
                    cout << "Consulta registrada como realizada.\n";
                }
                else
                {
                    cout << "Consulta nao realizada.\n";
                }

                cout << "Deseja alterar a data/hora e a duracao da consulta? (S/N): ";
                cin >> opcao;

                if (opcao == 'S' || opcao == 's')
                {
                    string dataHora, duracao;
                    cout << "Nova Data e Hora (formato: YYYY-MM-DD HH:mm): ";
                    cin >> dataHora;
                    cout << "Nova Duracao: ";
                    cin >> duracao;

                    consulta.setDataHora(dataHora);
                    consulta.setDuracao(duracao);
                    cout << "Consulta alterada com sucesso.\n";
                }
                else
                {
                    cout << "Consulta nao alterada.\n";
                }

                return;
            }
        }

        cout << "Consulta nao encontrada.\n";
    }

    void listarConsultas()
    {
        cout << "Lista de Consultas:\n";
        for (auto consulta : consultas)
        {
            cout << "Paciente: " << consulta.getPaciente()->Nome << ", Medico: " << consulta.getMedico()->Nome
                 << ", Data: " << consulta.getDataHora() << ", Duracao: " << consulta.getDuracao();
            if (consulta.getRealizada())
            {
                cout << " (Realizada)";
            }
            else
            {
                cout << " (Nao Realizada)";
            }
            cout << endl;
        }
    }
};

class App
{
private:
    GerenciadorPacientes gerenciadorPacientes;
    GerenciadorMedicos gerenciadorMedicos;
    GerenciadorConsultas gerenciadorConsultas;

public:
    void menuPacientes()
    {
        int opcao;
        do
        {
            cout << "\nMenu de Opcoes (Pacientes):\n";
            cout << "1. Incluir\n";
            cout << "2. Excluir\n";
            cout << "3. Alterar\n";
            cout << "4. Listar\n";
            cout << "5. Localizar\n";
            cout << "0. Voltar para menu anterior\n";
            cout << "Escolha uma opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                gerenciadorPacientes.incluirPaciente();
                break;
            case 2:
                gerenciadorPacientes.excluirPaciente();
                break;
            case 3:
                gerenciadorPacientes.alterarPaciente();
                break;
            case 4:
                gerenciadorPacientes.listarPacientes();
                break;
            case 5:
                gerenciadorPacientes.localizarPaciente();
                break;
            case 0:
                cout << "Saindo do menu de pacientes.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
            }
        } while (opcao != 0);
    }

    void menuMedicos()
    {
        int opcao;
        do
        {
            cout << "\nMenu de Opcoes (Medicos):\n";
            cout << "1. Incluir\n";
            cout << "2. Excluir\n";
            cout << "3. Alterar\n";
            cout << "4. Listar\n";
            cout << "5. Localizar\n";
            cout << "0. Voltar para menu anterior\n";
            cout << "Escolha uma opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                gerenciadorMedicos.incluirMedico();
                break;
            case 2:
                gerenciadorMedicos.excluirMedico();
                break;
            case 3:
                gerenciadorMedicos.alterarMedico();
                break;
            case 4:
                gerenciadorMedicos.listarMedicos();
                break;
            case 5:
                gerenciadorMedicos.localizarMedico();
                break;
            case 0:
                cout << "Saindo do menu de medicos.\n";
                break;
            default:
                cout << "Opcao inválida. Tente novamente.\n";
            }
        } while (opcao != 0);
    }

    void menuConsultas()
    {
        int opcao;
        do
        {
            cout << "\nMenu de Opcoes (Consultas):\n";
            cout << "1. Incluir Consulta\n";
            cout << "2. Excluir Consulta\n";
            cout << "3. Alterar Consulta\n";
            cout << "4. Listar Consultas\n";
            cout << "0. Voltar para menu anterior\n";
            cout << "Escolha uma opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                gerenciadorConsultas.incluirConsulta(gerenciadorPacientes, gerenciadorMedicos);
                break;
            case 2:
                gerenciadorConsultas.excluirConsulta(gerenciadorMedicos);
                break;
            case 3:
                gerenciadorConsultas.alterarConsulta(gerenciadorMedicos);
                break;
            case 4:
                gerenciadorConsultas.listarConsultas();
                break;
            case 0:
                cout << "Saindo do menu de consultas.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
            }
        } while (opcao != 0);
    }

    void executar()
    {
        int opcao;
        do
        {
            cout << "\nMenu Principal:\n";
            cout << "1. Gerenciar Pacientes\n";
            cout << "2. Gerenciar Medicos\n";
            cout << "3. Gerenciar Consultas\n";
            cout << "0. Sair\n";
            cout << "Escolha uma opcão: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                menuPacientes();
                break;
            case 2:
                menuMedicos();
                break;
            case 3:
                menuConsultas();
                break;
            case 0:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
            }
        } while (opcao != 0);
    }
};

int main()
{
    App app;
    app.executar();

    return 0;
}