#pragma once
#include <memory>
#include <string>
#include <vector>

namespace Botan {
    class AutoSeeded_RNG;
    class RSA_PublicKey;
    class RSA_PrivateKey;
    class PK_Encryptor_EME;
}

class chenor {

    public:
    ssize_t write(int fd, const void *buf, size_t count);
    std::string decrypt(const std::vector<char> &in, Botan::RSA_PrivateKey *pk);
    static Botan::RSA_PrivateKey* gen_key();
    //Since we are forward declaring these key types the compiler does not know
    // that one inherits the other, hence we will overload the function.
    chenor(Botan::RSA_PrivateKey *pk);
    chenor(Botan::RSA_PublicKey *pk=nullptr);

    private:
    std::shared_ptr<Botan::RSA_PublicKey> public_key;
    std::shared_ptr<Botan::AutoSeeded_RNG> rng;
    std::shared_ptr<Botan::PK_Encryptor_EME> pke;
    std::string eme;

};
