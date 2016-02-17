uiSeekerNumber = 0; -- -public -int
uiFleeerNumber = 0; -- -public -int
uiPursuitNumber = 0; -- -public -int
uiEvasionNumber = 0; -- -public -int
uiArrivalNumber = 0; -- -public -int
uiAvoiderNumber = 0; -- -public -int
uiWanderNumber = 0; -- -public -int
uiLeadFollowerNumber = 0; -- -public -int
uiSeparationerNumber = 0; -- -public -int
uiCohesionerNumber = 0; -- -public -int
uiAlignmenterNumber = 0; -- -public -int
uiFlockingerNumber = 0; -- -public -int
uiUnalignederNumber = 0; -- -public -int
uiPathFollowerNumber = 0; -- -public -int


function OnStart()
	-- Instatiate Seekers
	for i = 1, uiSeekerNumber, 1
		do
		  Entity = game.instantiate("Seeker");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end

	-- Instatiate Fleeers
	for i = 1, uiFleeerNumber, 1
		do
		  Entity = game.instantiate("Fleeer");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Pursuiters
	for i = 1, uiPursuitNumber, 1
		do
		  Entity = game.instantiate("Pursuiter");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Evasioners
	for i = 1, uiEvasionNumber, 1
		do
		  Entity = game.instantiate("Evasioner");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Arrivalers
	for i = 1, uiArrivalNumber, 1
		do
		  Entity = game.instantiate("Arrivaler");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Avoiders
	for i = 1, uiAvoiderNumber, 1
		do
		  Entity = game.instantiate("Avoider");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Wanderers
	for i = 1, uiWanderNumber, 1
		do
		  Entity = game.instantiate("Wanderer");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end

	-- Instatiate LeadFollowers
	for i = 1, uiLeadFollowerNumber, 1
		do
		  Entity = game.instantiate("LeadFollower");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
		
	-- Instatiate Separationers
	for i = 1, uiSeparationerNumber, 1
		do
		  Entity = game.instantiate("Separationer");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end
	
	-- Instatiate Cohesioners
	for i = 1, uiCohesionerNumber, 1
		do
		  Entity = game.instantiate("Cohesioner");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end	
		
	-- Instatiate Alignmenters
	for i = 1, uiAlignmenterNumber, 1
		do
		  Entity = game.instantiate("Alignmenter");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end	
		
	-- Instatiate Flockingers
	for i = 1, uiFlockingerNumber, 1
		do
		  Entity = game.instantiate("Flockinger");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end		
	
	-- Instatiate Unaligneders
	for i = 1, uiUnalignederNumber, 1
		do
		  Entity = game.instantiate("Unaligneder");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end			
	
	-- Instatiate PathFollowers
	for i = 1, uiPathFollowerNumber, 1
		do
		  Entity = game.instantiate("Follower");
		  Entity.transform:setPosition(r_vector2f(math.random(0.0, 1280.0), math.random(0.0, 720.0)));
		end		
end