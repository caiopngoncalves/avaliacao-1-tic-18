#include <iostream>
#include <vector>

using namespace std;

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
        
        this->cpf = _cpf;
    }

    string getDtNascimento() {
        return this->dtNascimento;
    }

    void setDtNascimento(string _dtNascimento) {
        
        this->dtNascimento = _dtNascimento;
    }
};

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
       
        this->crm = _crm;
    }

    string getEspecialidade() {
        return this->especialidade;
    }

    void setEspecialidade(string _especialidade) {
       
        this->especialidade = _especialidade;
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
        cout << "\nMenu Principal:\n";
        cout << "1. Gerenciar Pacientes\n";
        cout << "2. Gerenciar Medicos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        cin.ignore();  

        switch (opcao) {
            case 1:  // Para paciente
                int opcaoAuxiliar;
                do {
                    cout << "Informe a opcao (0-5): " << endl;
                    cout << "1. Incluir" << endl;
                    cout << "2. Excluir (por CPF)" << endl;
                    cout << "3. Alterar (por CPF)" << endl;
                    cout << "4. Listar" << endl;
                    cout << "5. Localizar (por CPF)" << endl;
                    cout << "0. Sair" << endl;
                    cin >> opcaoAuxiliar;

                    cin.ignore();  

                    string auxNome, auxCpf, auxDtNasc;
                    if (opcaoAuxiliar == 1) {
                        cout << "Informe o nome: ";
                        getline(cin >> ws, auxNome);

                        cout << "Informe o CPF: ";
                        getline(cin >> ws, auxCpf);

                        cout << "Informe a Data de Nascimento: ";
                        getline(cin >> ws, auxDtNasc);

                        Paciente* paciente = new Paciente(auxNome, auxCpf, auxDtNasc);
                        listaPacientes.push_back(paciente);
                    }
                    else if (opcaoAuxiliar == 2) {
                        cout << "Informe o CPF do paciente que deseja excluir: ";
                        getline(cin >> ws, auxCpf);

                        int posicao = localizaCpf(listaPacientes, auxCpf);
                        if (posicao >= 0) {
                            delete listaPacientes[posicao];
                            listaPacientes.erase(listaPacientes.begin() + posicao);
                        }
                        else {
                            cout << "Paciente nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 3) {
                        cout << "Informe o CPF do paciente que deseja alterar: ";
                        getline(cin >> ws, auxCpf);

                        int posicao = localizaCpf(listaPacientes, auxCpf);
                        if (posicao >= 0) {
                            cout << "Informe o novo nome: ";
                            getline(cin >> ws, auxNome);

                            cout << "Informe o novo CPF: ";
                            getline(cin >> ws, auxCpf);

                            cout << "Informe a nova Data de Nascimento: ";
                            getline(cin >> ws, auxDtNasc);

                            delete listaPacientes[posicao];
                            listaPacientes[posicao] = new Paciente(auxNome, auxCpf, auxDtNasc);
                        }
                        else {
                            cout << "Paciente nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 4) {
                        for (auto el : listaPacientes) {
                            cout << el->nome << endl;
                            cout << el->getCpf() << endl;
                            cout << el->getDtNascimento() << endl;
                            cout << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 5) {
                        cout << "Informe o CPF do paciente que deseja localizar: ";
                        getline(cin >> ws, auxCpf);

                        int posicao = localizaCpf(listaPacientes, auxCpf);
                        if (posicao >= 0) {
                            cout << listaPacientes.at(posicao)->nome << endl;
                        }
                        else {
                            cout << "Paciente nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar != 0) {
                        cout << "Opcao invalida" << endl;
                    }
                } while (opcaoAuxiliar != 0);

                break;

            case 2: // Para medico
                do {
                    cout << "Informe a opcao (0-5): " << endl;
                    cout << "1. Incluir" << endl;
                    cout << "2. Excluir (por CRM)" << endl;
                    cout << "3. Alterar (por CRM)" << endl;
                    cout << "4. Listar" << endl;
                    cout << "5. Localizar (por CRM)" << endl;
                    cout << "0. Sair" << endl;
                    cin >> opcaoAuxiliar;

                    cin.ignore(); 

                    string auxNome, auxCrm, auxEspecialidade;
                    if (opcaoAuxiliar == 1) {
                        cout << "Informe o nome: ";
                        getline(cin >> ws, auxNome);

                        cout << "Informe o CRM: ";
                        getline(cin >> ws, auxCrm);

                        cout << "Informe a Especialidade: ";
                        getline(cin >> ws, auxEspecialidade);

                        Medico* medico = new Medico(auxNome, auxCrm, auxEspecialidade);
                        listaMedicos.push_back(medico);
                    }
                    else if (opcaoAuxiliar == 2) {
                        cout << "Informe o CRM do medico que deseja excluir: ";
                        getline(cin >> ws, auxCrm);

                        int posicao = localizaCrm(listaMedicos, auxCrm);
                        if (posicao >= 0) {
                            delete listaMedicos[posicao];
                            listaMedicos.erase(listaMedicos.begin() + posicao);
                        }
                        else {
                            cout << "Medico nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 3) {
                        cout << "Informe o CRM do medico que deseja alterar: ";
                        getline(cin >> ws, auxCrm);

                        int posicao = localizaCrm(listaMedicos, auxCrm);
                        if (posicao >= 0) {
                            cout << "Informe o novo nome: ";
                            getline(cin >> ws, auxNome);

                            cout << "Informe o novo CRM: ";
                            getline(cin >> ws, auxCrm);

                            cout << "Informe a nova Especialidade: ";
                            getline(cin >> ws, auxEspecialidade);

                            delete listaMedicos[posicao];
                            listaMedicos[posicao] = new Medico(auxNome, auxCrm, auxEspecialidade);
                        }
                        else {
                            cout << "Medico nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 4) {
                        for (auto el : listaMedicos) {
                            cout << el->nome << endl;
                            cout << el->getCrm() << endl;
                            cout << el->getEspecialidade() << endl;
                            cout << endl;
                        }
                    }
                    else if (opcaoAuxiliar == 5) {
                        cout << "Informe o CRM do medico que deseja localizar: ";
                        getline(cin >> ws, auxCrm);

                        int posicao = localizaCrm(listaMedicos, auxCrm);
                        if (posicao >= 0) {
                            cout << listaMedicos.at(posicao)->nome << endl;
                        }
                        else {
                            cout << "Medico nao encontrado" << endl;
                        }
                    }
                    else if (opcaoAuxiliar != 0) {
                        cout << "Opcao invalida" << endl;
                    }
                } while (opcaoAuxiliar != 0);
                break;

            case 0:
                cout << "Saindo do programa.\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 0);


    return 0;
}