#pragma once

namespace nano
{
class store;
class unchecked_info;
class unchecked_key;
class write_transaction;
class unchecked_map
{
public:
	unchecked_map (nano::store & store);
	void add (nano::write_transaction const & transaction, nano::unchecked_key const & key, nano::unchecked_info const & info);
private:
	nano::store & store;
};
}
