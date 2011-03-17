// Copyright 2011 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CHAIN_CHAIN_HPP_20110317
#define BOOST_CHAIN_CHAIN_HPP_20110317

#include <memory> // for std::allocator
#include <string> // for std::string

namespace boost { namespace chains {

    /**
     * Definition of the basic chain interface.
     */
    template <class CharT>
    struct basic_chain {

        /// Default constructor
        basic_chain() {}

        /// Construct from CharT const *
        basic_chain(CharT const *) {}

        /// Construct from std::string
        template <class StrAllocator>
        basic_chain(std::basic_string<CharT, StrAllocator> const &) {}

    };

    typedef basic_chain<char> chain;

    template <class CharT, class Allocator = std::allocator<CharT> >
    struct basic_builder {

        basic_chain<CharT> const chain() {
            // FIXME implement the builder on demand here
            return basic_chain<CharT>();
        }

    };

    typedef basic_builder<char> builder;

    /**
     * The generic shift-left operator that introduces the ADL-found
     * `append` free function, that implements the actual appending
     * to the builder using the builder interface.
     */
    template <class CharT, class Allocator, class T>
    inline basic_builder<CharT, Allocator> const &
    operator<<(basic_builder<CharT, Allocator> const & builder_, T const & data) {
        // FIXME implement the append extension point
        // append(builder_, data); // find via ADL
        return builder_;
    }
    
} /* chains */

} /* boost */

#endif /* BOOST_CHAIN_CHAIN_HPP_20110317 */
