#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Medico {
    string crm;
    string especialidade;
public:
    string nome;

    Medico(string _nome, string _crm, string _especialidade) {
        this->nome = _nome;
        this->setCrm(_crm);
        this->setEspecialidade(_especialidade);
    }

    string getCrm() {
        return this->crm;
    }

    void setCrm(string _crm) {
        /* validar quantidade de caracteres 11 ou 14
        */
        this->crm = _crm;
    }

    string getEspecialidade() {
        return this->especialidade;
    }

    void setEspecialidade(string _especialidade) {
        /* validar quantidade de caracteres e formato
        */
        this->especialidade = _especialidade;
    }
};

class Paciente {
    string cpf;
    string dtNascimento; //ideal tipo Data ou struct tm
public:
    string nome;

    Paciente(string _nome, string _cpf, string _dtNascimento) {
        this->nome = _nome;
        this->setCpf(_cpf);
        this->setDtNascimento(_dtNascimento);
    }

    string getCpf() {
        return this->cpf;
    }

    void setCpf(string _cpf) {
        /* validar quantidade de caracteres 11 ou 14
        */
        this->cpf = _cpf;
    }

    string getDtNascimento() {
        return this->dtNascimento;
    }

    void setDtNascimento(string _dtNascimento) {
        /* validar quantidade de caracteres e formato
        */
        this->dtNascimento = _dtNascimento;
    }
};

// função para localizar CPF em um vector<Paciente*>
int localizaCpf(vector<Paciente*> pacientes, string cpf) {
    int i = 0;
    for (auto el : pacientes) {
        if (el->getCpf() == cpf) {
            return i;
        }
        i++;
    }

    return -1;
}

int localizaCrm(vector<Medico*> medicos, string crm) {
    int i = 0;
    for (auto el : medicos) {
        if (el->getCrm() == crm) {
            return i;
        }
        i++;
    }

    return -1;
}

int main() {
    int opcao;
    vector<Paciente*> listaPacientes;
    vector<Medico*> listaMedicos;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Gerenciar Pacientes\n";
        cout << "2. Gerenciar Medicos\n";
        cout << "0. Sair\n";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer após ler a opção

        switch (opcao) {
        case 1:
            // Gerenciar Pacientes
            int auxPaciente;
            do {
                cout << "\nMenu de Gerenciamento de Pacientes:\n";
                cout << "1. Incluir Paciente\n";
                cout << "2. Excluir Paciente (por CPF)\n";
                cout << "3. Alterar Paciente (por CPF)\n";
                cout << "4. Listar Pacientes\n";
                cout << "5. Localizar Paciente (por CPF)\n";
                cout << "0. Voltar ao Menu Principal\n";
                cout << "Escolha uma opcao: ";
                cin >> auxPaciente;
                cin.ignore();

                string auxNome, auxCpf, auxDtNasc;

                if (auxPaciente == 1) {
                    cout << "Informe o nome: ";
                    getline(cin, auxNome);

                    cout << "Informe o CPF: ";
                    getline(cin, auxCpf);

                    cout << "Informe a Data de Nascimento: ";
                    getline(cin, auxDtNasc);

                    Paciente* paciente = new Paciente(auxNome, auxCpf, auxDtNasc);

                    listaPacientes.push_back(paciente);
                }
                else if (auxPaciente == 2) {
                    cout << "Informe o CPF do paciente que deseja excluir: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        delete listaPacientes[posicao];
                        listaPacientes.erase(listaPacientes.begin() + posicao);
                        cout << "Paciente excluido com sucesso." << endl;
                    }
                    else {
                        cout << "Paciente nao encontrado." << endl;
                    }
                }
                else if (auxPaciente == 3) {
                    cout << "Informe o CPF do paciente que deseja alterar: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        cout << "Informe o novo nome: ";
                        getline(cin, auxNome);
                        cout << "Informe o novo CPF: ";
                        getline(cin, auxCpf);
                        cout << "Informe a nova Data de Nascimento: ";
                        getline(cin, auxDtNasc);

                        listaPacientes[posicao]->nome = auxNome;
                        listaPacientes[posicao]->setCpf(auxCpf);
                        listaPacientes[posicao]->setDtNascimento(auxDtNasc);

                        cout << "Paciente alterado com sucesso." << endl;
                    }
                    else {
                        cout << "Paciente nao encontrado." << endl;
                    }
                }
                else if (auxPaciente == 4) {
                    cout << "\nLista de Pacientes:\n";
                    for (auto el : listaPacientes) {
                        cout << "Nome: " << el->nome << endl;
                        cout << "CPF: " << el->getCpf() << endl;
                        cout << "Data de Nascimento: " << el->getDtNascimento() << endl;
                        cout << endl;
                    }
                }
                else if (auxPaciente == 5) {
                    cout << "Informe o CPF do paciente que deseja localizar: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        cout << "Nome: " << listaPacientes[posicao]->nome << endl;
                        cout << "CPF: " << listaPacientes[posicao]->getCpf() << endl;
                        cout << "Data de Nascimento: " << listaPacientes[posicao]->getDtNascimento() << endl;
                    }
                    else {
                        cout << "Paciente nao encontrado." << endl;
                    }
                }
                else if (auxPaciente == 0) {
                    // Voltar ao Menu Principal
                    break;
                }
                else {
                    cout << "Opcao invalida. Tente novamente.\n";
                }
            } while (auxPaciente != 0);
            break;

        case 2:
            // Gerenciar Medicos
            int auxMedico;
            do {
                cout << "\nMenu de Gerenciamento de Medicos:\n";
                cout << "1. Incluir Medico\n";
                cout << "2. Excluir Medico (por CRM)\n";
                cout << "3. Alterar Medico (por CRM)\n";
                cout << "4. Listar Medicos\n";
                cout << "5. Localizar Medico (por CRM)\n";
                cout << "0. Voltar ao Menu Principal\n";
                cout << "Escolha uma opcao: ";
                cin >> auxMedico;
                cin.ignore();

                string auxNome, auxCRM, auxEspec;

                if (auxMedico == 1) {
                    cout << "Informe o Nome: ";
                    getline(cin, auxNome);

                    cout << "Informe o CRM: ";
                    getline(cin, auxCRM);

                    cout << "Informe a Especialidade: ";
                    getline(cin, auxEspec);

                    Medico* medico = new Medico(auxNome, auxCRM, auxEspec);

                    listaMedicos.push_back(medico);
                }
                else if (auxMedico == 2) {
                    cout << "Informe o CRM do medico que deseja excluir: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        delete listaMedicos[posicao];
                        listaMedicos.erase(listaMedicos.begin() + posicao);
                        cout << "Medico excluido com sucesso." << endl;
                    }
                    else {
                        cout << "Medico nao encontrado." << endl;
                    }
                }
                else if (auxMedico == 3) {
                    cout << "Informe o CRM do medico que deseja alterar: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        cout << "Informe o novo nome: ";
                        getline(cin, auxNome);
                        cout << "Informe o novo CRM: ";
                        getline(cin, auxCRM);
                        cout << "Informe a nova Especialidade: ";
                        getline(cin, auxEspec);

                        listaMedicos[posicao]->nome = auxNome;
                        listaMedicos[posicao]->setCrm(auxCRM);
                        listaMedicos[posicao]->setEspecialidade(auxEspec);

                        cout << "Medico alterado com sucesso." << endl;
                    }
                    else {
                        cout << "Medico não encontrado." << endl;
                    }
                }
                else if (auxMedico == 4) {
                    cout << "\nLista de Medicos:\n";
                    for (auto el : listaMedicos) {
                        cout << "Nome: " << el->nome << endl;
                        cout << "CRM: " << el->getCrm() << endl;
                        cout << "Especialidade: " << el->getEspecialidade() << endl;
                        cout << endl;
                    }
                }
                else if (auxMedico == 5) {
                    cout << "Informe o CRM do medico que deseja localizar: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        cout << "Nome: " << listaMedicos[posicao]->nome << endl;
                        cout << "CRM: " << listaMedicos[posicao]->getCrm() << endl;
                        cout << "Especialidade: " << listaMedicos[posicao]->getEspecialidade() << endl;
                    }
                    else {
                        cout << "Medico nao encontrado." << endl;
                    }
                }
                else if (auxMedico == 0) {
                    // Voltar ao Menu Principal
                    break;
                }
                else {
                    cout << "Opcao invalida. Tente novamente.\n";
                }
            } while (auxMedico != 0);
            break;

        case 0:
            cout << "Saindo do programa.\n";
            break;

        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    // Limpar a memória alocada para pacientes e médicos
    for (auto paciente : listaPacientes) {
        delete paciente;
    }
    for (auto medico : listaMedicos) {
        delete medico;
    }

    return 0;
}
