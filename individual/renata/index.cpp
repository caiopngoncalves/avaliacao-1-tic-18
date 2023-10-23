#include <iostream>
#include <vector>

using namespace std;

class Paciente{
    string cpf;
    string dtNascimento; //ideal tipo Data ou struct tm
    public:
        string nome;

        Paciente(string _nome,string _cpf,string _dtNascimento){
            this->nome = _nome;
            this->setCpf(_cpf);
            this->setDtNascimento(_dtNascimento);
        }

        string getCpf(){
            return this->cpf;
        }

        void setCpf(string _cpf){
            /* validar quantidade de caracteres 11 ou 14
            */
           this->cpf = _cpf;
        }

        string getDtNascimento(){
            return this->dtNascimento;
        }

        void setDtNascimento(string _dtNascimento){
            /* validar quantidade de caracteres e formato
            */
           this->dtNascimento = _dtNascimento;
        } 
};

class Medico{
    string crm;
    string especialidade; 
    public:
        string nome;

        Medico(string _nome,string _crm,string _especialidade){
            this->nome = _nome;
            this->setCrm(_crm);
            this->setEspecialidade(_especialidade);
        }

        string getCrm(){
            return this->crm;
        }

        void setCrm(string _crm){
            /* validar quantidade de caracteres 11 ou 14
            */
           this->crm = _crm;
        }

        string getEspecialidade(){
            return this->especialidade;
        }

        void setEspecialidade(string _especialidade){
            /* validar quantidade de caracteres e formato
            */
           this->especialidade = _especialidade;
        } 
};

// funcao para localizar cpf em um vector<Paciente*>
int localizaCpf(vector<Paciente*> pacientes, string cpf){
    int i=0;
    for(auto el : pacientes){
        if(el->getCpf() == cpf){
            return i;
        }
        i++;
    }

    return -1;
}

int localizaCrm(vector<Medico*> medicos, string crm){
    int i=0;
    for(auto el : medicos){
        if(el->getCrm() == crm){
            return i;
        }
        i++;
    }

    return -1;
}

int main(){

    int opcao, ;
    vector<Paciente*> listaPacientes;
    vector<Medico*> listaMedicos;

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
            case 1:  //paciente
            int aux;
    do{
        cout << "Informe a opção (0-5): " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir (por CPF)" << endl;
        cout << "3. Alterar (por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        string auxNome, auxCpf, auxDtNasc;
        if(opcao==1){
            cout << "Informe o nome: ";
            getline(cin >> ws, auxNome);

            cout << "Informe o CPF: ";
            getline(cin >> ws, auxCpf);

            cout << "Informe a Data de Nascimento: ";
            getline(cin >> ws, auxDtNasc);

            Paciente *paciente = new Paciente(auxNome, auxCpf, auxDtNasc);

            //TODO: procurar em listaPacientes pelo cpf do novo paciente

            listaPacientes.push_back(paciente);
        }
        else if(opcao==2){
            cout << "Informe o CPF do paciente que deseja excluir: ";
            getline(cin >> ws, auxCpf);

            /*
                buscar pelo paciente em listaPacientes
            */
        }
        else if(opcao==3){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf);

            /*
                buscar pelo paciente em listaPacientes
                em seguida pedir os dados que deseja alterar
            */
        }else if(opcao==4){
            for(auto el : listaPacientes){
                cout << el->nome << endl;
                cout << el->getCpf() << endl;
                cout << el->getDtNascimento() << endl;
                cout << endl;
            }
        }else if(opcao==5){
            cout << "Informe o CPF do paciente que deseja alterar: ";
            getline(cin >> ws, auxCpf); 

            int posicao = localizaCpf(listaPacientes,auxCpf);

            if(posicao < 0)
                cout << "Paciente não encontrado" << endl;
            else{
                cout << listaPacientes.at(posicao)->nome << endl;
            }
        }else if(opcao==0){
            // sair desse menu
        } else{
            cout << "Opção inválida" << endl;
        }
    }while(opcao != 0);
                
                break;

            case 2: //medico
                do{
        cout << "Informe a opção (0-5): " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir (por CRM)" << endl;
        cout << "3. Alterar (por CRM)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CRM)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        string auxNome, auxCrm, auxEspecialidade;
        if(opcao==1){
            cout << "Informe o nome: ";
            getline(cin >> ws, auxNome);

            cout << "Informe o CRM: ";
            getline(cin >> ws, auxCrm);

            cout << "Informe a Especialidade: ";
            getline(cin >> ws, auxEspecialidade);

            Medico *medico = new Medico(auxNome, auxCrm, auxEspecialidade);

            //TODO: procurar em listaPacientes pelo cpf do novo paciente

            listaMedicos.push_back(medico);
        }
        else if(opcao==2){
            cout << "Informe o CRM do paciente que deseja excluir: ";
            getline(cin >> ws, auxCrm);

            /*
                buscar pelo paciente em listaPacientes
            */
        }
        else if(opcao==3){
            cout << "Informe o CRM do medico que deseja alterar: ";
            getline(cin >> ws, auxCrm);

            /*
                buscar pelo paciente em listaPacientes
                em seguida pedir os dados que deseja alterar
            */
        }else if(opcao==4){
            for(auto el : listaMedicos){
                cout << el->nome << endl;
                cout << el->getCrm() << endl;
                cout << el->getEspecialidade() << endl;
                cout << endl;
            }
        }else if(opcao==5){
            cout << "Informe o CRM do medico que deseja alterar: ";
            getline(cin >> ws, auxCrm); 

            int posicao = localizaCrm(listaMedicos,auxCrm);

            if(posicao < 0)
                cout << "Medico não encontrado" << endl;
            else{
                cout << listaMedicos.at(posicao)->nome << endl;
            }
        }else if(opcao==0){
            // sair desse menu
        } else{
            cout << "Opção inválida" << endl;
        }
    }while(opcao != 0);
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