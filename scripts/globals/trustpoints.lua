-- --------------------------- --
-- Do a check for Trust Tokens --
-- --------------------------- --

function trustPoints(killer, mob)
local trustTokens = killer:getVar("TrustTokens");
local tokenCap = 35;

local AdelheidTokens = killer:getVar("CurrentTokens_Adelheid");
local AdelheidPoints = killer:getVar("CurrentPoints_Adelheid");

local AyameTokens = killer:getVar("CurrentTokens_Ayame");
local AyamePoints = killer:getVar("CurrentPoints_Ayame");

local CurillaTokens = killer:getVar("CurrentTokens_Curilla");
local CurillaPoints = killer:getVar("CurrentPoints_Curilla");

local DarcullinTokens = killer:getVar("CurrentTokens_Darcullin");
local DarcullinPoints = killer:getVar("CurrentPoints_Darcullin");

local ExcenmilleTokens = killer:getVar("CurrentTokens_Excenmille");
local ExcenmillePoints = killer:getVar("CurrentPoints_Excenmille");

local KupipiTokens = killer:getVar("CurrentTokens_Kupipi");
local KupipiPoints = killer:getVar("CurrentPoints_Kupipi");

local LionTokens = killer:getVar("CurrentTokens_Lion");
local LionPoints = killer:getVar("CurrentPoints_Lion");

local NanaaTokens = killer:getVar("CurrentTokens_Nanaa");
local NanaaPoints = killer:getVar("CurrentPoints_Nanaa");

local NajiTokens = killer:getVar("CurrentTokens_Naji");
local NajiPoints = killer:getVar("CurrentPoints_Naji");

local ZeidTokens = killer:getVar("CurrentTokens_Zeid");
local ZeidPoints = killer:getVar("CurrentPoints_Zeid");


local curillaTrib = killer:getVar("CURILLA_TRIB_FIGHT");
local excenmilleTrib = killer:getVar("EXCEN_TRIB_FIGHT");
local ayameTrib = killer:getVar("AYAME_TRIB_FIGHT");
local najiTrib = killer:getVar("NAJI_TRIB_FIGHT");

local kupipiTrib = killer:getVar("KUPIPI_TRIB_FIGHT");
local nanaaTrib = killer:getVar("NANAA_TRIB_FIGHT");


local lionTrib = killer:getVar("LION_TRIB_FIGHT");
local darcullinTrib = killer:getVar("DARC_TRIB_FIGHT");
local zeidTrib = killer:getVar("ZEID_TRIB_FIGHT");
local adelheidTrib = killer:getVar("ADEL_TRIB_FIGHT");

local pet;
local trustpoint = mob:getBaseExp() * 1;




   
	    if ((((not killer:isUniqueAlly(75)) and (najiTrib == 3)) or ((not killer:isUniqueAlly(76)) and (kupipiTrib == 3)) or 
		    ((not killer:isUniqueAlly(77)) and (ayameTrib == 3)) or ((not killer:isUniqueAlly(78)) and (nanaaTrib == 3)) or 
			((not killer:isUniqueAlly(79)) and (curillaTrib == 3)) or ((not killer:isUniqueAlly(80)) and (excenmilleTrib == 3)) or 
			((not killer:isUniqueAlly(81)) and (darcullinTrib == 3)) or ((not killer:isUniqueAlly(82)) and (adelheidTrib == 3)) or 
			((not killer:isUniqueAlly(86)) and (lionTrib == 3)) or ((not killer:isUniqueAlly(91)) and (zeidTrib == 3))) and killer:getMainLvl() >= 75) then-- Means that they are in the party.  Need to list all because it displays trust points
	        killer:PrintToPlayer("You receive "..trustpoint.." Trust Points!!!", 0x15);
            -- Naji
	        if ((not killer:isUniqueAlly(75)) and (najiTrib == 3)) then
		        killer:setVar("CurrentPoints_Naji", NajiPoints + trustpoint);
			    NajiPoints = killer:getVar("CurrentPoints_Naji");
			    if (NajiPoints > 10000) then
			        killer:setVar("CurrentTokens_Naji", NajiTokens + 1);
				    NajiTokens = killer:getVar("CurrentTokens_Naji");
	                killer:PrintToPlayer("You obtain "..NajiTokens.." Trust Token(Naji).  Total: ("..NajiTokens.."/"..tokenCap..").", 0x15);
				    killer:setVar("CurrentPoints_Naji", NajiPoints - 10000);
	            end
	        end	       
            -- Kupipi
	        if ((not killer:isUniqueAlly(76)) and (kupipiTrib == 3)) then
		        killer:setVar("CurrentPoints_Kupipi", KupipiPoints + trustpoint);
			    KupipiPoints = killer:getVar("CurrentPoints_Kupipi");
			    if (KupipiPoints > 10000) then
					killer:setVar("CurrentTokens_Kupipi", KupipiTokens + 1);
					KupipiTokens = killer:getVar("CurrentTokens_Kupipi");
					killer:PrintToPlayer("You obtain "..KupipiTokens.." Trust Token(Kupipi).  Total: ("..KupipiTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Kupipi", KupipiPoints - 10000);
				end
			end	
			-- Ayame
			if ((not killer:isUniqueAlly(77)) and (ayameTrib == 3)) then
				killer:setVar("CurrentPoints_Ayame", AyamePoints + trustpoint);
				AyamePoints = killer:getVar("CurrentPoints_Ayame");
				if (AyamePoints > 10000) then
					killer:setVar("CurrentTokens_Ayame", AyameTokens + 1);
					AyameTokens = killer:getVar("CurrentTokens_Ayame");
					killer:PrintToPlayer("You obtain "..AyameTokens.." Trust Token(Ayame).  Total: ("..AyameTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Ayame", AyamePoints - 10000);
				end
			end	
			-- Nanaa
			if ((not killer:isUniqueAlly(78)) and (nanaaTrib == 3)) then
				killer:setVar("CurrentPoints_Nanaa", NanaaPoints + trustpoint);
				NanaaPoints = killer:getVar("CurrentPoints_Nanaa");
				if (NanaaPoints > 10000) then
					killer:setVar("CurrentTokens_Nanaa", NanaaTokens + 1);
					NanaaTokens = killer:getVar("CurrentTokens_Nanaa");
					killer:PrintToPlayer("You obtain "..NanaaTokens.." Trust Token(Nanaa).  Total: ("..NanaaTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Nanaa", NanaaPoints - 10000);
				end
			end	
			-- Curilla
			if ((not killer:isUniqueAlly(79)) and (curillaTrib == 3)) then
				killer:setVar("CurrentPoints_Curilla", CurillaPoints + trustpoint);
				CurillaPoints = killer:getVar("CurrentPoints_Curilla");
				if (CurillaPoints > 10000) then
					killer:setVar("CurrentTokens_Curilla", CurillaTokens + 1);
					CurillaTokens = killer:getVar("CurrentTokens_Curilla");
					killer:PrintToPlayer("You obtain "..CurillaTokens.." Trust Token(Curilla).  Total: ("..CurillaTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Curilla", CurillaPoints - 10000);
				end
			end	
			-- Excenmille
			if ((not killer:isUniqueAlly(80)) and (excenmilleTrib == 3)) then
				killer:setVar("CurrentPoints_Excenmille", ExcenmillePoints + trustpoint);
				ExcenmillePoints = killer:getVar("CurrentPoints_Excenmille");
				if (ExcenmillePoints > 10000) then
					killer:setVar("CurrentTokens_Excenmille", ExcenmilleTokens + 1);
					ExcenmilleTokens = killer:getVar("CurrentTokens_Excenmille");
					killer:PrintToPlayer("You obtain "..ExcenmilleTokens.." Trust Token(Excenmille).  Total: ("..ExcenmilleTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Excenmille", ExcenmillePoints - 10000);
				end
			end	
			-- Darcullin
			if ((not killer:isUniqueAlly(81)) and (darcullinTrib == 3)) then
				killer:setVar("CurrentPoints_Darcullin", DarcullinPoints + trustpoint);
				DarcullinPoints = killer:getVar("CurrentPoints_Darcullin");
				if (DarcullinPoints > 10000) then
					killer:setVar("CurrentTokens_Darcullin", DarcullinTokens + 1);
					DarcullinTokens = killer:getVar("CurrentTokens_Darcullin");
					killer:PrintToPlayer("You obtain "..DarcullinTokens.." Trust Token(Darcullin).  Total: ("..DarcullinTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Darcullin", DarcullinPoints - 10000);
				end
			end			
			-- Adelheid
			if ((not killer:isUniqueAlly(82)) and (adelheidTrib == 3)) then
				killer:setVar("CurrentPoints_Adelheid", AdelheidPoints + trustpoint);
				AdelheidPoints = killer:getVar("CurrentPoints_Adelheid");
				if (AdelheidPoints > 10000) then
					killer:setVar("CurrentTokens_Adelheid", AdelheidTokens + 1);
					AdelheidTokens = killer:getVar("CurrentTokens_Adelheid");
					killer:PrintToPlayer("You obtain "..AdelheidTokens.." Trust Token(Adelheid).  Total: ("..AdelheidTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Adelheid", AdelheidPoints - 10000);
				end
			end			
			-- Lion
			if ((not killer:isUniqueAlly(86)) and (lionTrib == 3)) then
				killer:setVar("CurrentPoints_Lion", LionPoints + trustpoint);
				LionPoints = killer:getVar("CurrentPoints_Lion");
				if (LionPoints > 10000) then
					killer:setVar("CurrentTokens_Lion", LionTokens + 1);
					LionTokens = killer:getVar("CurrentTokens_Lion");
					killer:PrintToPlayer("You obtain "..LionTokens.." Trust Token(Lion).  Total: ("..LionTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Lion", LionPoints - 10000);
				end
			end		
			
			-- Zeid
			if ((not killer:isUniqueAlly(91)) and (zeidTrib == 3)) then
				killer:setVar("CurrentPoints_Zeid", ZeidPoints + trustpoint);
				ZeidPoints = killer:getVar("CurrentPoints_Zeid");
				if (ZeidPoints > 10000) then
					killer:setVar("CurrentTokens_Zeid", ZeidTokens + 1);
					ZeidTokens = killer:getVar("CurrentTokens_Zeid");
					killer:PrintToPlayer("You obtain "..ZeidTokens.." Trust Token(Zeid).  Total: ("..ZeidTokens.."/"..tokenCap..").", 0x15);
					killer:setVar("CurrentPoints_Zeid", ZeidPoints - 10000);
				end
			end
		
		end
	
	
end;	