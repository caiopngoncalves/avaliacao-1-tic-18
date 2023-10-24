#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente
{
public:
    string cpf;
    string nome;
    string dtNascimento;

    Paciente(const string &cpf, const string &nome, const string &dtNascimento)
        : cpf(cpf), nome(nome), dtNascimento(dtNascimento) {}
};

class Medico
{
public:
    string crm;
    string nome;
    string especialidade;

    Medico(const string &crm, const string &nome, const string &especialidade)
        : crm(crm), nome(nome), especialidade(especialidade) {}
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

        pacientes.push_back(Paciente(cpf, nome, dtNascimento));
    }

    void excluirPaciente()
    {
        string cpf;
        cout << "Informe o CPF do paciente a ser excluído: ";
        cin >> cpf;

        for (auto it = pacientes.begin(); it != pacientes.end(); ++it)
        {
            if (it->cpf == cpf)
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
        string cpf;
        cout << "Informe o CPF do paciente a ser alterado: ";
        cin >> cpf;

        for (auto &paciente : pacientes)
        {
            if (paciente.cpf == cpf)
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, paciente.nome);
                cout << "Nova Data de Nascimento: ";
                cin >> paciente.dtNascimento;
                cout << "Paciente alterado com sucesso.\n";
                return;
            }
        }

        cout << "Paciente nao encontrado.\n";
    }

    void listarPacientes()
    {
        cout << "Lista de Pacientes:\n";
        for (const auto &paciente : pacientes)
        {
            cout << "CPF: " << paciente.cpf << ", Nome: " << paciente.nome << ", Data de Nascimento: " << paciente.dtNascimento << endl;
        }
    }

    void localizarPaciente()
    {
        string cpf;
        cout << "Informe o CPF do paciente: ";
        cin >> cpf;

        for (const auto &paciente : pacientes)
        {
            if (paciente.cpf == cpf)
            {
                cout << "Paciente encontrado:\n";
                cout << "CPF: " << paciente.cpf << ", Nome: " << paciente.nome << ", Data de Nascimento: " << paciente.dtNascimento << endl;
                return;
            }
        }

        cout << "Paciente nao encontrado.\n";
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

        medicos.push_back(Medico(crm, nome, especialidade));
    }

    void excluirMedico()
    {
        string crm;
        cout << "Informe o CRM do medico a ser excluido: ";
        cin >> crm;

        for (auto it = medicos.begin(); it != medicos.end(); ++it)
        {
            if (it->crm == crm)
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
        string crm;
        cout << "Informe o CRM do medico a ser alterado: ";
        cin >> crm;

        for (auto &medico : medicos)
        {
            if (medico.crm == crm)
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, medico.nome);
                cout << "Nova Especialidade: ";
                getline(cin, medico.especialidade);
                cout << "Medico alterado com sucesso.\n";
                return;
            }
        }

        cout << "Medico nao encontrado.\n";
    }

    void listarMedicos()
    {
        cout << "Lista de Medicos:\n";
        for (const auto &medico : medicos)
        {
            cout << "CRM: " << medico.crm << ", Nome: " << medico.nome << ", Especialidade: " << medico.especialidade << endl;
        }
    }

    void localizarMedico()
    {
        string crm;
        cout << "Informe o CRM do medico: ";
        cin >> crm;

        for (const auto &medico : medicos)
        {
            if (medico.crm == crm)
            {
                cout << "Medico encontrado:\n";
                cout << "CRM: " << medico.crm << ", Nome: " << medico.nome << ", Especialidade: " << medico.especialidade << endl;
                return;
            }
        }

        cout << "Medico nao encontrado.\n";
    }
};

class App
{
private:
    GerenciadorPacientes gerenciadorPacientes;
    GerenciadorMedicos gerenciadorMedicos;

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

    void executar()
    {
        int opcao;
        do
        {
            cout << "\nMenu Principal:\n";
            cout << "1. Gerenciar Pacientes\n";
            cout << "2. Gerenciar Medicos\n";
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
