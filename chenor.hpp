#pragma once
#include <memory>
#include <botan/rsa.h>
#include "Fixed_Output_RNG.hpp"
#include <botan/pubkey.h>
#include <botan/auto_rng.h>
#include <botan/init.h>

namespace chenor {

    ssize_t write(int fd, void *buf, size_t count);
    void init();

    // TODO, Find out why PrivateKey destructors cause segfaults.
    extern Botan::RSA_PrivateKey *private_key;
    //extern Fixed_Output_RNG *rng;
    extern std::unique_ptr<Botan::AutoSeeded_RNG> rng;

    void setup();
}
