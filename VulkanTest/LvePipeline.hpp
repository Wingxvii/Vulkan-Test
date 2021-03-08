#pragma once

#include <string>
#include <vector>

namespace lve {
	class LvePipeline
	{
	public:
		LvePipeline(const std::string& vertPath, const std::string& fragPath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath);
	};
}

