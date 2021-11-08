#include <nano/node/unchecked_map.hpp>

#include <nano/secure/store.hpp>

nano::unchecked_map::unchecked_map (nano::store & store) :
	store{ store }
{
}

void nano::unchecked_map::add (nano::write_transaction const & transaction, nano::unchecked_key const & key, nano::unchecked_info const & info)
{
	store.unchecked.put (transaction, key, info);
}
