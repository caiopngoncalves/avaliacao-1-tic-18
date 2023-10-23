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

      cout << "Novo nome: ";
      cin.ignore();
      getline(cin, novoNome);
      setNome(novoNome);

      cout << "Nova data de nascimento (dd/mm/aaaa): ";
      cin >> novaDtNascimento;
      setDtNascimento(novaDtNascimento);

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

int main() {
  vector<Paciente> pacientes;
  int opcao;
  Paciente paciente;

  while (true) {
    cout << "\nMenu de Pacientes:" << endl
         << "1. Incluir" << endl
         << "2. Excluir (por CPF)" << endl
         << "3. Alterar (por CPF)" << endl
         << "4. Listar" << endl
         << "5. Localizar (por CPF)" << endl
         << "0. Sair" << endl;
    cout << "Escolha um dos numeros acima: ";
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
      return 0;
    default:
      cout << "Opção inválida. Tente novamente." << endl;
      break;
    }
  }
  return 0;
}
