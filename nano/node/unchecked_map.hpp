#pragma once

#include <nano/secure/store.hpp>

#include <deque>

namespace nano
{
class hash_or_account;
class store;
class transaction;
class unchecked_info;
class unchecked_key;
class write_transaction;
class unchecked_map
{
public:
	using iterator = nano::unchecked_store::iterator;
public:
	unchecked_map (nano::store & store);
	void put (nano::write_transaction const & transaction, nano::hash_or_account const & dependency, nano::unchecked_info const & info);
	std::pair<iterator, iterator> equal_range (nano::transaction const & transaction, nano::block_hash const & dependency);
	std::pair<iterator, iterator> full_range (nano::transaction const & transaction);
	std::vector<nano::unchecked_info> get (nano::transaction const &, nano::block_hash const &);
	bool exists (nano::transaction const & transaction, nano::unchecked_key const & key) const;
	void del (nano::write_transaction const & transaction, nano::unchecked_key const & key);
	void clear (nano::write_transaction const & transaction);
	size_t count (nano::transaction const & transaction) const;
private:
	nano::store & store;
};
}
