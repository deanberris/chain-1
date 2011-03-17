// Copyright 2011 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** This test defines the minimal interface requirement for the
 *  chain data type.
 */

#include <boost/chain/chain.hpp>
#include <string>

namespace chains = boost::chains;

int main(int argc, const char *argv[]) {

    // A chain is default constructible
    chains::chain a;

    // This is the defacto way for building a chain
    // from literals and other data types. This should
    // be familiar because it looks pretty much like how
    // std::ostringstream works.
    chains::builder b;
    b << "Hello, world!";

    // We allow for assignment, in which case a chain is
    // really a proxy.
    chains::chain c = b.chain();

    // We allow for constructing a chain from a char const *
    chains::chain d = "Construction from char const * supported!";

    // We allow for constructing a chain from a std::string
    chains::chain e = std::string("Construct from a std::string!");

    return 0;
}
