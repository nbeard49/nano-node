#include <nano/node/unchecked_map.hpp>

#include <nano/secure/store.hpp>

#include <boost/range/join.hpp>

nano::unchecked_map::unchecked_map (nano::store & store) :
	store{ store }
{
}

void nano::unchecked_map::put (nano::write_transaction const & transaction, nano::hash_or_account const & dependency, nano::unchecked_info const & info)
{
	store.unchecked.put (transaction, dependency, info);
}

auto nano::unchecked_map::equal_range (nano::transaction const & transaction, nano::block_hash const & dependency) -> std::pair<iterator, iterator>
{
	return store.unchecked.equal_range (transaction, dependency);
}

auto nano::unchecked_map::full_range (nano::transaction const & transaction) -> std::pair<iterator, iterator>
{
	return store.unchecked.full_range (transaction);
}

std::vector<nano::unchecked_info> nano::unchecked_map::get (nano::transaction const & transaction, nano::block_hash const & hash)
{
	return store.unchecked.get (transaction, hash);
}

bool nano::unchecked_map::exists (nano::transaction const & transaction, nano::unchecked_key const & key) const
{
	return store.unchecked.exists (transaction, key);
}

void nano::unchecked_map::del (nano::write_transaction const & transaction, nano::unchecked_key const & key)
{
	store.unchecked.del (transaction, key);
}

void nano::unchecked_map::clear (nano::write_transaction const & transaction)
{
	store.unchecked.clear (transaction);
}

size_t nano::unchecked_map::count (nano::transaction const & transaction) const
{
	return store.unchecked.count (transaction);
}
