namespace gmk
{
	AssetsManager::AssetsManager()
		: m_AssetsKeyword(SFGMKR_ASSETSMANAGER_KEYWORD)
	{

	}

	AssetsManager::~AssetsManager()
	{

	}

	AssetsManager* AssetsManager::GetSingleton()
	{
		static AssetsManager singleton;

		return &singleton;
	}

	r_string AssetsManager::getAssetPath(r_string _path)
	{
		if (_path.find(m_AssetsKeyword) != r_string::npos)
		{
			r_string assets_path = SFMLCanvas::project->getAssetsPath();

			r_string path = _path;
			
			if(assets_path.size())
				path = assets_path + "\\" + _path.substr(m_AssetsKeyword.size());

			if(SFGMKR_ASSETSMANAGER_DEBUG)
				std::cout << "[INFO] AssetsManager : file " << path << " requested" << std::endl;

			return path;
		}
		else
		{
			if (SFGMKR_ASSETSMANAGER_DEBUG)
				std::cout << "[ERROR] AssetsManager : requested bad asset path" << std::endl;

			return "NULL";
		}
	}
}