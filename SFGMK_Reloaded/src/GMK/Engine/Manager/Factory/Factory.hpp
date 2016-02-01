/*--------------------------------------------------------------------------------------------------

	@author		GMK
	@date		28/01/2016
	@brief		Classe permettant l'instanciation dynamique de prefabs (notamment depuis les scripts)

--------------------------------------------------------------------------------------------------*/

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "stdafx.h"


namespace gmk
{
	class Factory : public SingletonTemplate<Factory>
	{
		friend class SingletonTemplate<Factory>;

		private:
			Factory();
			~Factory();

			std::unordered_map<r_string, Prefab*> m_Prefabs;

		public:
			r_void loadPrefabs(const r_string& _Path);
			r_void savePrefabs(const r_string& _Path);
			r_bool createPrefab(GameObject* _Model);
			r_bool removePrefab(const r_string& _PrefabId);

			GameObject* instantiate(const r_string& _PrefabId);
	};
}


#endif