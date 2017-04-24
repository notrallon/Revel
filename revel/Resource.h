#pragma once
#include <string>

namespace rvl {
	template <class T> friend class ResourceManager;

	class Resource {
	public:
								Resource(const unsigned int handle, 
										 const std::string& name, 
										 const std::string& path);
								~Resource();

		const std::string&		GetName()		{ return m_name; }
		const std::string&		GetFileName()	{ return m_filename; }
		const std::string&		GetPath()		{ return m_path; }
		const unsigned int&		GetHandle()		{ return m_handle; }
		const int&				GetRefCount()	{ return m_refCount; }

	private:
		std::string				m_name;
		std::string				m_filename;
		std::string				m_path;
		unsigned int			m_handle;

		unsigned int			m_refCount;
		void					IncRefCount()	{ m_refCount++; }
		void					DecRefCount()	{ m_refCount--; }
	};
}