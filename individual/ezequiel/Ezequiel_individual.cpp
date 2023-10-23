#include <ctime>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Paciente {
private:
  string cpf;
  string nome;
  string dtnascimento;

public:
  Paciente() {}

  // Getters e Setters

  void setCPF(string novoCPF) {
    while (!regex_match(novoCPF, regex("\\d{11}"))) {
      cout << "CPF invalido. Deve conter 11 digitos numericos. Digite novamente: ";
      cin >> novoCPF;
    }
    cpf = novoCPF;
  }

  void setNome(const string &novoNome) {
    // Você pode adicionar validações adicionais aqui, se necessário
    nome = novoNome;
  }

  void setDtNascimento(string &novaDtNascimento) {
    while (!regex_match(novaDtNascimento, regex("\\d{2}/\\d{2}/\\d{4}")) ||
           !dataValida(novaDtNascimento)) {
      cout << "Data de nascimento invalida. Deve estar no formato dd/mm/aaaa. Digite novamente: ";
      cin >> novaDtNascimento;
    }
    dtnascimento = novaDtNascimento;
  }

  string getCPF() const { return cpf; }
  string getNome() const { return nome; }
  string getDtNascimento() const { return dtnascimento; }

  bool dataValida(const string &data) {
    // Utilize a expressão regular para validar a data no formato "dd/mm/aaaa"
    regex dataPattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}");

    return regex_match(data, dataPattern);
  }

  // Funções de manipulação de pacientes
  int buscarPacientePorCPF(const vector<Paciente> &pacientes, const string &cpf) {
    for (size_t i = 0; i < pacientes.size(); i++) {
      if (pacientes[i].getCPF() == cpf) {
        return i; // Retorna o índice do paciente encontrado
      }
    }
    return -1; // Retorna -1 se o paciente não for encontrado
  }

  void incluirPaciente(vector<Paciente> &pacientes) {
    string cpf, nome, dtnascimento;
    cout << "CPF do paciente: ";
    cin >> cpf;

    if (buscarPacientePorCPF(pacientes, cpf) != -1) {
      cout << "CPF ja existe. Nao e possivel incluir o paciente." << endl;
      return;
    }

    setCPF(cpf);

    cout << "Nome do paciente: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Data de nascimento (dd/mm/aaaa): ";
    cin >> dtnascimento;

    setNome(nome);
    setDtNascimento(dtnascimento);

    pacientes.push_back(*this);
    cout << "Paciente incluido com sucesso!" << endl;
  }

  void excluirPaciente(vector<Paciente> &pacientes) {
    string cpf;
    cout << "CPF do paciente a ser excluido: ";
    cin >> cpf;
    int indice = buscarPacientePorCPF(pacientes, cpf);
    if (indice != -1) {
      pacientes.erase(pacientes.begin() + indice);
      cout << "Paciente excluido com sucesso!" << endl;
    } else {
      cout << "Paciente nao encontrado." << endl;
    }
  }

  void alterarPaciente(vector<Paciente> &pacientes) {
    string cpf;
    cout << "CPF do paciente a ser alterado: ";
    cin >> cpf;
    int indice = buscarPacientePorCPF(pacientes, cpf);
    if (indice != -1) {
      cout << "Paciente encontrado. Realize as alteracoes:" << endl;
      string novoNome, novaDtNascimento;

      cout << "Novo CPF: ";
      cin>>cpf;
      pacientes[indice].setCPF(cpf);

      cout << "Novo nome: ";
      cin.ignore();
      getline(cin, novoNome);
      pacientes[indice].setNome(novoNome);

      cout << "Nova data de nascimento (dd/mm/aaaa): ";
      cin >> novaDtNascimento;
      pacientes[indice].setDtNascimento(novaDtNascimento);

      cout << "Dados do paciente alterados com sucesso!" << endl;
    } else {
      cout << "Paciente nao encontrado." << endl;
    }
  }

  void listarPacientes(const vector<Paciente> &pacientes) {
    cout << "\nLista de Pacientes:" << endl;
    for (const Paciente &paciente : pacientes) {
      cout << "CPF: " << paciente.getCPF() << endl;
      cout << "Nome: " << paciente.getNome() << endl;
      cout << "Data de Nascimento: " << paciente.getDtNascimento() << endl;
    }
  }

  void localizarPaciente(const vector<Paciente> &pacientes) {
    string cpf;
    cout << "CPF do paciente a ser localizado: ";
    cin >> cpf;
    int indice = buscarPacientePorCPF(pacientes, cpf);
    if (indice != -1) {
      const Paciente &pacienteEncontrado = pacientes[indice];
      cout << "Paciente encontrado:" << endl;
      cout << "CPF: " << pacienteEncontrado.getCPF() << endl;
      cout << "Nome: " << pacienteEncontrado.getNome() << endl;
      cout << "Data de Nascimento: " << pacienteEncontrado.getDtNascimento() << endl;
    } else {
      cout << "Paciente nao encontrado." << endl;
    }
  }
};

class Medico {
private:
  string crm;
  string nome;
  string especialidade;

public:
  Medico(string novoCRM, string novoNome, string novaEspecialidade) {
    setCRM(novoCRM);
    setNome(novoNome);
    setEspecialidade(novaEspecialidade);
}

  // Getters e Setters

  void setCRM(string novoCRM) {
    while (!regex_match(novoCRM, regex("\\d{5}"))) {
      cout << "CRM invalido. Deve conter 5 dígitos numericos. Digite novamente: ";
      cin >> novoCRM;
    }
    crm = novoCRM;
  }

  void setNome(const string &novoNome) {
    // Você pode adicionar validações adicionais aqui, se necessário
    nome = novoNome;
  }

  void setEspecialidade(const string &novaEspecialidade) {
    // Você pode adicionar validações adicionais aqui, se necessário
    especialidade = novaEspecialidade;
  }

  string getCRM() const { return crm; }
  string getNome() const { return nome; }
  string getEspecialidade() const { return especialidade; }

  // Funções de manipulação de médicos
  int buscarMedicoPorCRM(const vector<Medico> &medicos, const string &crm) {
    for (size_t i = 0; i < medicos.size(); i++) {
      if (medicos[i].getCRM() == crm) {
        return i; // Retorna o índice do médico encontrado
      }
    }
    return -1; // Retorna -1 se o médico não for encontrado
  }

  void incluirMedico(vector<Medico> &medicos) {
    string crm, nome, especialidade;
    cout << "CRM do medico: ";
    cin >> crm;

    if (buscarMedicoPorCRM(medicos, crm) != -1) {
      cout << "CRM ja existe. Nao e possivel incluir o medico." << endl;
      return;
    }

    setCRM(crm);

    cout << "Nome do medico: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Especialidade do medico: ";
    getline(cin, especialidade);

    setNome(nome);
    setEspecialidade(especialidade);

    medicos.push_back(*this);
    cout << "Medico incluido com sucesso!" << endl;
  }

  void incluirMedico(vector<Medico> &medicos) {
    string crm, nome, especialidade;
    cout << "CRM do medico: ";
    cin >> crm;

    if (buscarMedicoPorCRM(medicos, crm) != -1) {
        cout << "CRM ja existe. Nao e possivel incluir o medico." << endl;
        return;
    }

    cout << "Nome do medico: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Especialidade do medico: ";
    getline(cin, especialidade);

    Medico novoMedico(crm, nome, especialidade);
    medicos.push_back(novoMedico);
    cout << "Medico incluido com sucesso!" << endl;
}


  void alterarMedico(vector<Medico> &medicos) {
    string crm;
    cout << "CRM do medico a ser alterado: ";
    cin >> crm;
    int indice = buscarMedicoPorCRM(medicos, crm);
    if (indice != -1) {
      cout << "Medico encontrado. Realize as alteracoes:" << endl;
      string novoNome, novaEspecialidade;

      cout << "Novo CRM: ";
      cin >> crm;
      medicos[indice].setCRM(crm);

      cout << "Novo nome: ";
      cin.ignore();
      getline(cin, novoNome);
      medicos[indice].setNome(novoNome);

      cout << "Nova especialidade: ";
      getline(cin, novaEspecialidade);
      medicos[indice].setEspecialidade(novaEspecialidade);

      cout << "Dados do medico alterados com sucesso!" << endl;
    } else {
      cout << "Médico não encontrado." << endl;
    }
  }

  void listarMedicos(const vector<Medico> &medicos) {
    cout << "\nLista de Medicos:" << endl;
    for (const Medico &medico : medicos) {
      cout << "CRM: " << medico.getCRM() << endl;
      cout << "Nome: " << medico.getNome() << endl;
      cout << "Especialidade: " << medico.getEspecialidade() << endl;
    }
  }

  void localizarMedico(const vector<Medico> &medicos) {
    string crm;
    cout << "CRM do medico a ser localizado: ";
    cin >> crm;
    int indice = buscarMedicoPorCRM(medicos, crm);
    if (indice != -1) {
      const Medico &medicoEncontrado = medicos[indice];
      cout << "Medico encontrado:" << endl;
      cout << "CRM: " << medicoEncontrado.getCRM() << endl;
      cout << "Nome: " << medicoEncontrado.getNome() << endl;
      cout << "Especialidade: " << medicoEncontrado.getEspecialidade() << endl;
    } else {
      cout << "Médico não encontrado." << endl;
    }
  }
};

void gerenciarPacientes(vector<Paciente> &pacientes);
void gerenciarMedicos(vector<Medico> &medicos);

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    int opcao;

    while (true) {
        cout << "\nMenu Principal:" << endl
             << "1. Gerenciar Pacientes" << endl
             << "2. Gerenciar Medicos" << endl
             << "0. Sair" << endl;
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            gerenciarPacientes(pacientes);
            break;
        case 2:
            gerenciarMedicos(medicos);
            break;
        case 0:
            return 0;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}


void gerenciarPacientes(vector<Paciente> &pacientes) {
    int opcao;
    Paciente paciente;

    while (true) {
        cout << "\nMenu de Pacientes:" << endl
             << "1. Incluir" << endl
             << "2. Excluir (por CPF)" << endl
             << "3. Alterar (por CPF)" << endl
             << "4. Listar" << endl
             << "5. Localizar (por CPF)" << endl
             << "0. Voltar" << endl;
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            paciente.incluirPaciente(pacientes);
            break;
        case 2:
            paciente.excluirPaciente(pacientes);
            break;
        case 3:
            paciente.alterarPaciente(pacientes);
            break;
        case 4:
            paciente.listarPacientes(pacientes);
            break;
        case 5:
            paciente.localizarPaciente(pacientes);
            break;
        case 0:
            return;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }
}

void gerenciarMedicos(vector<Medico> &medicos) {
    int opcao;
    Medico medico;

    while (true) {
        cout << "\nMenu de Medicos:" << endl
             << "1. Incluir" << endl
             << "2. Excluir (por CRM)" << endl
             << "3. Alterar (por CRM)" << endl
             << "4. Listar" << endl
             << "5. Localizar (por CRM)" << endl
             << "0. Voltar" << endl;
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            medico.incluirMedico(medicos);
            break;
        case 2:
            medico.excluirMedico(medicos);
            break;
        case 3:
            medico.alterarMedico(medicos);
            break;
        case 4:
            medico.listarMedicos(medicos);
            break;
        case 5:
            medico.localizarMedico(medicos);
            break;
        case 0:
            return;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    }
}