/*
 * This file is part of poco-dht (http://github.com/alemansec/poco-dht).
 *
 * poco-dht is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 *
 * poco-dht is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with poco-dht.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file src/include/libdht/requestlist.h
 * @brief simple class keeping a list of requests together.
 */
#ifndef LIBDHT_REQUESTLIST_H
#define LIBDHT_REQUESTLIST_H

#include "libdht/request.h"

#include <list>

namespace libdht {

    /**
     * @brief list of requests, with various accessors.
     */
    class RequestList {
        public:
            /**
             * @brief default constructor.
             */
            RequestList();

            /**
             * @brief default destructor.
             */
            ~RequestList();

            /**
             * @brief returns current amount of requests in list.
             * @return integer total number of requests in current list.
             */
            int count();

            /**
             * @brief clears current list of requests.
             * @return void
             */
            void clear();

            /**
             * @brief appends given request to end of list.
             * @param Request \a req request object to append to list.
             * @return void
             */
            void append(Request &req);

        protected:
            std::list<Request> _requestList; /**< internal list of requests */
    };

}

#endif /* LIBDHT_REQUESTLIST_H */

