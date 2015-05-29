#pragma once
#include <memory>
#include <string>
#include <vector>

namespace Botan {
    class RSA_PublicKey;
    class RSA_PrivateKey;
}

namespace chenor {

    ssize_t write(int fd, const void *buf, size_t count);
    std::string decrypt(const std::vector<char> &in, Botan::RSA_PrivateKey *pk);
    Botan::RSA_PrivateKey* gen_key();

    //Since we are forward declaring these key types the compiler does not know
    // that one inherits the other, hence we will overload the function.
    void setup(Botan::RSA_PrivateKey *pk);
    void setup(Botan::RSA_PublicKey *pk=nullptr);
}
