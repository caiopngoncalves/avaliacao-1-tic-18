#include <iostream>
#include <vector>
#include <string>
#include <cctype>

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
        if (_crm.size() == 11 || _crm.size() == 14) {
            bool isNumeric = true;
            for (char c : _crm) {
                if (!std::isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }

            if (isNumeric) {
                this->crm = _crm;
            } else {
                cout << "O CRM contem caracteres nao numericos." << endl;
            }
        } else {
            cout << "O CRM nao possui 11 ou 14 caracteres." << endl;
        }
    }

    string getEspecialidade() {
        return this->especialidade;
    }

    void setEspecialidade(string _especialidade) {
        if (_especialidade.size() >= 3) {
            this->especialidade = _especialidade;
        } else {
            cout << "Especialidade invalida." << endl;
        }
    }
};

class Paciente {
    string cpf;
    string dtNascimento;
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
        if (_cpf.size() == 11 || _cpf.size() == 14) {
            bool isNumeric = true;
            for (char c : _cpf) {
                if (!std::isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }

            if (isNumeric) {
                this->cpf = _cpf;
            } else {
                cout << "\nO CPF contem caracteres nao numericos." << endl;
            }
        } else {
            cout << "\nO CPF nao possui 11 ou 14 caracteres." << endl;
        }
    }

    string getDtNascimento() {
        return this->dtNascimento;
    }

    void setDtNascimento(string _dtNascimento) {
        if (_dtNascimento.size() >= 8) {
            this->dtNascimento = _dtNascimento;
        } else {
            cout << "\nData de Nascimento invalida." << endl;
        }
    }
};

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
        cout << "\n----- Menu Principal -----\n";
        cout << "1. Menu Pacientes\n";
        cout << "2. Menu Medicos\n";
        cout << "0. Sair\n";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
        case 1:
            int auxPaciente;
            do {
                cout << "\n----- Menu de Gerenciamento de Pacientes -----\n";
                cout << "1. Incluir Paciente\n";
                cout << "2. Excluir Paciente (por CPF)\n";
                cout << "3. Alterar Paciente (por CPF)\n";
                cout << "4. Listar Pacientes\n";
                cout << "5. Localizar Paciente (por CPF)\n";
                cout << "0. Voltar ao Menu Principal\n";
                cout << "\nEscolha uma opcao: ";
                cin >> auxPaciente;
                cin.ignore();

                string auxNome, auxCpf, auxDtNasc;

                if (auxPaciente == 1) {
                    cout << "\nInforme o nome: ";
                    getline(cin, auxNome);

                    cout << "Informe o CPF: ";
                    getline(cin, auxCpf);

                    cout << "Informe a Data de Nascimento: ";
                    getline(cin, auxDtNasc);

                    Paciente* paciente = new Paciente(auxNome, auxCpf, auxDtNasc);

                    listaPacientes.push_back(paciente);
                }
                else if (auxPaciente == 2) {
                    cout << "\nInforme o CPF do paciente que deseja excluir: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        delete listaPacientes[posicao];
                        listaPacientes.erase(listaPacientes.begin() + posicao);
                        cout << "\nPaciente excluido com sucesso." << endl;
                    }
                    else {
                        cout << "\nPaciente nao encontrado." << endl;
                    }
                }
                else if (auxPaciente == 3) {
                    cout << "\nInforme o CPF do paciente que deseja alterar: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        cout << "\nInforme o novo nome: ";
                        getline(cin, auxNome);
                        cout << "Informe o novo CPF: ";
                        getline(cin, auxCpf);
                        cout << "Informe a nova Data de Nascimento: ";
                        getline(cin, auxDtNasc);

                        listaPacientes[posicao]->nome = auxNome;
                        listaPacientes[posicao]->setCpf(auxCpf);
                        listaPacientes[posicao]->setDtNascimento(auxDtNasc);

                        cout << "\nPaciente alterado com sucesso." << endl;
                    }
                    else {
                        cout << "\nPaciente nao encontrado." << endl;
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
                    cout << "\nInforme o CPF do paciente que deseja localizar: ";
                    getline(cin, auxCpf);
                    int posicao = localizaCpf(listaPacientes, auxCpf);
                    if (posicao >= 0) {
                        cout << "Nome: " << listaPacientes[posicao]->nome << endl;
                        cout << "CPF: " << listaPacientes[posicao]->getCpf() << endl;
                        cout << "Data de Nascimento: " << listaPacientes[posicao]->getDtNascimento() << endl;
                    }
                    else {
                        cout << "\nPaciente nao encontrado." << endl;
                    }
                }
                else if (auxPaciente == 0) {

                    break;
                }
                else {
                    cout << "\nOpcao invalida. Tente novamente.\n";
                }
            } while (auxPaciente != 0);
            break;

        case 2:
            int auxMedico;
            do {
                cout << "\n----- Menu de Gerenciamento de Medicos -----\n";
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
                    cout << "\nInforme o Nome: ";
                    getline(cin, auxNome);

                    cout << "Informe o CRM: ";
                    getline(cin, auxCRM);

                    cout << "Informe a Especialidade: ";
                    getline(cin, auxEspec);

                    Medico* medico = new Medico(auxNome, auxCRM, auxEspec);

                    listaMedicos.push_back(medico);
                }
                else if (auxMedico == 2) {
                    cout << "\nInforme o CRM do medico que deseja excluir: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        delete listaMedicos[posicao];
                        listaMedicos.erase(listaMedicos.begin() + posicao);
                        cout << "\nMedico excluido com sucesso." << endl;
                    }
                    else {
                        cout << "\nMedico nao encontrado." << endl;
                    }
                }
                else if (auxMedico == 3) {
                    cout << "\nInforme o CRM do medico que deseja alterar: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        cout << "\nInforme o novo nome: ";
                        getline(cin, auxNome);
                        cout << "Informe o novo CRM: ";
                        getline(cin, auxCRM);
                        cout << "Informe a nova Especialidade: ";
                        getline(cin, auxEspec);

                        listaMedicos[posicao]->nome = auxNome;
                        listaMedicos[posicao]->setCrm(auxCRM);
                        listaMedicos[posicao]->setEspecialidade(auxEspec);

                        cout << "\nMedico alterado com sucesso." << endl;
                    }
                    else {
                        cout << "\nMedico não encontrado." << endl;
                    }
                }
                else if (auxMedico == 4) {
                    cout << "\n--- Lista de Medicos ---\n";
                    for (auto el : listaMedicos) {
                        cout << "Nome: " << el->nome << endl;
                        cout << "CRM: " << el->getCrm() << endl;
                        cout << "Especialidade: " << el->getEspecialidade() << endl;
                        cout << endl;
                    }
                }
                else if (auxMedico == 5) {
                    cout << "\nInforme o CRM do medico que deseja localizar: ";
                    getline(cin, auxCRM);
                    int posicao = localizaCrm(listaMedicos, auxCRM);
                    if (posicao >= 0) {
                        cout << "\nNome: " << listaMedicos[posicao]->nome << endl;
                        cout << "CRM: " << listaMedicos[posicao]->getCrm() << endl;
                        cout << "Especialidade: " << listaMedicos[posicao]->getEspecialidade() << endl;
                    }
                    else {
                        cout << "\nMedico nao encontrado." << endl;
                    }
                }
                else if (auxMedico == 0) {

                    break;
                }
                else {
                    cout << "\nOpcao invalida. Tente novamente.\n";
                }
            } while (auxMedico != 0);
            break;

        case 0:
            cout << "\nSaindo do programa.\n";
            break;

        default:
            cout << "\nOpcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    for (auto paciente : listaPacientes) {
        delete paciente;
    }
    for (auto medico : listaMedicos) {
        delete medico;
    }

    return 0;
}