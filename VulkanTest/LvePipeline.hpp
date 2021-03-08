#pragma once

#include "lveDevice.hpp"

#include <string>
#include <vector>


namespace lve {
	struct PipelineConfigInfo {};

	class LvePipeline
	{
	public:
		LvePipeline(LveDevice &device, const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& configInfo);
		~LvePipeline() {}

		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(int32_t width, uint32_t height);
	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}

