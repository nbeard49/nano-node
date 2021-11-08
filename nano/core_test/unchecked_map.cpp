#include <nano/node/unchecked_map.hpp>

#include <nano/lib/blockbuilders.hpp>
#include <nano/lib/logger_mt.hpp>
#include <nano/secure/store.hpp>
#include <nano/secure/utility.hpp>
#include <nano/test_common/testutil.hpp>

#include <gtest/gtest.h>

#include <memory>

namespace
{
class context
{
public:
	context () :
		store{ nano::make_store (logger, nano::unique_path (), nano::dev::constants) },
		unchecked{ *store }
	{
	}
	nano::logger_mt logger;
	std::unique_ptr<nano::store> store;
	nano::unchecked_map unchecked;
};
std::shared_ptr<nano::block> block ()
{
	nano::block_builder builder;
	return builder.state ()
		.account (nano::dev::genesis_key.pub)
		.previous (nano::dev::genesis->hash ())
		.representative (nano::dev::genesis_key.pub)
		.balance (nano::dev::constants.genesis_amount - 1)
		.link (nano::dev::genesis_key.pub)
		.sign (nano::dev::genesis_key.prv, nano::dev::genesis_key.pub)
		.work (0)
		.build_shared ();
}
}

TEST (unchecked_map, construction)
{
	context context;
}

TEST (unchecked_map, add_one)
{
	context context;
	nano::unchecked_info info{ block (), nano::dev::genesis_key.pub, nano::seconds_since_epoch () };
	nano::unchecked_key key{ info.block->previous (), info.block->hash () };
	context.unchecked.add (context.store->tx_begin_write (), key, info);
}
