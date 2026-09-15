#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

class Astronauta {
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:
    Astronauta(string cpf, string nome, int idade) {
        this->cpf = cpf;
        this->nome = nome;
        this->idade = idade;
        vivo = true;
        disponivel = true;
    }



    string getCpf() {
    return cpf;
}
string getNome() {
    return nome;
}

int getIdade() {
    return idade;
}

bool estaVivo() {
    return vivo;
}

bool estaDisponivel() {
    return disponivel;
}

void embarcar() {
    disponivel = false;
}

void desembarcar() {
    disponivel = true;
}

void morrer() {
    vivo = false;
    disponivel = false;
}

};

class Voo {
private:
    int codigo;
    string estado;
    vector<string> cpfs;

public:
    Voo(int codigo) {
        this->codigo = codigo;
        estado = "planejado";
    }

        int getCodigo() {
        return codigo;
    }

    string getEstado() {
        return estado;
    }

    bool estaPlanejado() {
        return estado == "planejado";
    }

    int getQuantidadeAstronautas() {
        return cpfs.size();
    }

    string getCpf(int posicao) {
        return cpfs[posicao];
    }

     bool temAstronauta(string cpf) {
        for (int i = 0; i < cpfs.size(); i++) {
            if (cpfs[i] == cpf) {
                return true;
            }
        }

        return false;
    }

    void adicionarAstronauta(string cpf) {
        cpfs.push_back(cpf);
    }

    bool removerAstronauta(string cpf) {
        for (int i = 0; i < cpfs.size(); i++) {
            if (cpfs[i] == cpf) {
                cpfs.erase(cpfs.begin() + i);
                return true;
            }
        }

        return false;
    }

        void lancar() {
        estado = "em curso";
    }

    void explodir() {
        estado = "finalizado com explosao";
    }

    void finalizar() {
        estado = "finalizado com sucesso";
    }
};

class Agencia {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf) {
    for (int i = 0; i < astronautas.size(); i++) {
        if (astronautas[i].getCpf() == cpf) {
            return i;
        }
    }

    return -1;
}

int buscarVoo(int codigo) {
        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getCodigo() == codigo) {
                return i;
            }
        }

        return -1;
    }

    int buscarVooEmCurso(string cpf) {
        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() == "em curso"
                && voos[i].temAstronauta(cpf)) {
                return voos[i].getCodigo();
            }
        }

        return -1;
    }

public:
    void cadastrarAstronauta(string cpf, string nome, int idade) {
        if (buscarAstronauta(cpf) != -1) {
            cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
            return;
        }

        Astronauta astronauta(cpf, nome, idade);
        astronautas.push_back(astronauta);

        cout << "OK: astronauta " << cpf << " cadastrado" << endl;
    }

        void cadastrarVoo(int codigo) {
        if (buscarVoo(codigo) != -1) {
            cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            return;
        }

        Voo voo(codigo);
        voos.push_back(voo);

        cout << "OK: voo " << codigo << " cadastrado" << endl;
    }

        void adicionarAstronauta(string cpf, int codigo) {
        int posicaoAstronauta = buscarAstronauta(cpf);
        int posicaoVoo = buscarVoo(codigo);

        if (posicaoAstronauta == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        if (posicaoVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (!voos[posicaoVoo].estaPlanejado()) {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (!astronautas[posicaoAstronauta].estaVivo()) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }

        if (voos[posicaoVoo].temAstronauta(cpf)) {
            cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
            return;
        }

        voos[posicaoVoo].adicionarAstronauta(cpf);

        cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
    }

        void removerAstronauta(string cpf, int codigo) {
        int posicaoAstronauta = buscarAstronauta(cpf);
        int posicaoVoo = buscarVoo(codigo);

        if (posicaoAstronauta == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        if (posicaoVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (!voos[posicaoVoo].estaPlanejado()) {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (!voos[posicaoVoo].temAstronauta(cpf)) {
            cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
            return;
        }

        voos[posicaoVoo].removerAstronauta(cpf);

        cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
    }

        void lancarVoo(int codigo) {
        int posicaoVoo = buscarVoo(codigo);

        if (posicaoVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (!voos[posicaoVoo].estaPlanejado()) {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (voos[posicaoVoo].getQuantidadeAstronautas() == 0) {
            cout << "ERRO: voo " << codigo << " sem astronautas" << endl;
            return;
        }

        for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posicaoVoo].getCpf(i);
            int posicaoAstronauta = buscarAstronauta(cpf);

            if (!astronautas[posicaoAstronauta].estaVivo()) {
                cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
                return;
            }

            if (!astronautas[posicaoAstronauta].estaDisponivel()) {
                cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
                return;
            }
        }

        for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posicaoVoo].getCpf(i);
            int posicaoAstronauta = buscarAstronauta(cpf);

            astronautas[posicaoAstronauta].embarcar();

        }

        voos[posicaoVoo].lancar();

        cout << "OK: voo " << codigo << " lancado" << endl;
    }

        void finalizarVoo(int codigo) {
        int posicaoVoo = buscarVoo(codigo);

        if (posicaoVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[posicaoVoo].getEstado() != "em curso") {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posicaoVoo].getCpf(i);
            int posicaoAstronauta = buscarAstronauta(cpf);

            astronautas[posicaoAstronauta].desembarcar();
        }

        voos[posicaoVoo].finalizar();

        cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
    }

        void explodirVoo(int codigo) {
        int posicaoVoo = buscarVoo(codigo);

        if (posicaoVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[posicaoVoo].getEstado() != "em curso") {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {
            string cpf = voos[posicaoVoo].getCpf(i);
            int posicaoAstronauta = buscarAstronauta(cpf);

            astronautas[posicaoAstronauta].morrer();
        }

        voos[posicaoVoo].explodir();

        cout << "OK: voo " << codigo << " explodiu" << endl;
    }

    void listarMortos() {
    cout << "ASTRONAUTAS MORTOS" << endl;

    bool encontrou = false;

    for (int i = 0; i < astronautas.size(); i++) {
        if (!astronautas[i].estaVivo()) {
            encontrou = true;

            cout << astronautas[i].getCpf() << " "
                 << astronautas[i].getNome() << " - voos:";

            bool encontrouVoo = false;

            for (int j = 0; j < voos.size(); j++) {
                if (voos[j].temAstronauta(astronautas[i].getCpf())
                    && !voos[j].estaPlanejado()) {

                    cout << " " << voos[j].getCodigo();
                    encontrouVoo = true;
                }
            }

            if (!encontrouVoo) {
                cout << " nenhum";
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }
}

        void listarVoos() {
        string estados[4] = {
            "planejado",
            "em curso",
            "finalizado com sucesso",
            "finalizado com explosao"
        };

        for (int e = 0; e < 4; e++) {
            cout << "VOOS " << estados[e] << endl;

            bool encontrou = false;

            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].getEstado() == estados[e]) {
                    encontrou = true;

                    cout << voos[i].getCodigo() << ": ";

                    if (voos[i].getQuantidadeAstronautas() == 0) {
                        cout << "sem astronautas";
                    } else {
                        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
                            string cpf = voos[i].getCpf(j);

                            int posicao = buscarAstronauta(cpf);

                            if (j > 0) {
                                cout << ", ";
                            }

                            cout << cpf << " " << astronautas[posicao].getNome();
                        }
                    }

                    cout << endl;
                }
            }

            if (!encontrou) {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void listarAstronautas() {
        cout << "LISTA DE ASTRONAUTAS" << endl;

        string grupos[3] = {
            "disponiveis",
            "em voo",
            "mortos"
        };

        for (int g = 0; g < 3; g++) {
            cout << "== " << grupos[g] << " ==" << endl;

            bool encontrou = false;

            for (int i = 0; i < astronautas.size(); i++) {
                int codigoVoo = buscarVooEmCurso(astronautas[i].getCpf());
                bool entra = false;

                if (g == 0) {
                    entra = astronautas[i].estaVivo() && codigoVoo == -1;
                } else if (g == 1) {
                    entra = astronautas[i].estaVivo() && codigoVoo != -1;
                } else {
                    entra = !astronautas[i].estaVivo();
                }

                if (entra) {
                    encontrou = true;

                    cout << astronautas[i].getCpf() << " "
                         << astronautas[i].getNome() << " ("
                         << astronautas[i].getIdade() << " anos)";

                    if (g == 1) {
                        cout << " - voo " << codigoVoo;
                    }

                    cout << endl;
                }
            }

            if (!encontrou) {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void historico(string cpf) {
        int posicaoAstronauta = buscarAstronauta(cpf);

        if (posicaoAstronauta == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        cout << "HISTORICO DE " << astronautas[posicaoAstronauta].getNome() << endl;

        bool encontrou = false;

        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].temAstronauta(cpf) && !voos[i].estaPlanejado()) {
                cout << "voo " << voos[i].getCodigo() << ": "
                     << voos[i].getEstado() << endl;
                encontrou = true;
            }
        }

        if (!encontrou) {
            cout << "(nenhum voo)" << endl;
        }
    }

};


int main() {
    Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else if (comando == "LISTAR_ASTRONAUTAS") {
            agencia.listarAstronautas();
        } else if (comando == "HISTORICO") {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
