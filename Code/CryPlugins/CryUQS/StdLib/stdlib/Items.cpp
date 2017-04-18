// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#include "StdAfx.h"
#include <CrySerialization/Math.h>

// *INDENT-OFF* - <hard to read code and declarations due to inconsistent indentation>

namespace UQS
{
	namespace StdLib
	{

		template <typename T>
		T GetValueInitializedItem()
		{
			return T();
		}

		// for Client::STypeWrapper<> types whose underlying type is Vec3
		template <class TVec3BasedTypeWrapper>
		TVec3BasedTypeWrapper GetVec3BasedTypeWrapperZero()
		{
			return TVec3BasedTypeWrapper(Vec3(ZERO));
		}

#if UQS_SCHEMATYC_SUPPORT
		void ConvertEntityIdToEntityIdWrapper(const EntityId& input, EntityIdWrapper& output)
		{
			output.value = input;
		}

		void ConvertEntityIdWrapperToEntityId(const EntityIdWrapper& input, EntityId& output)
		{
			output = input.value;
		}

		template <class TVec3BasedTypeWrapper>
		void ConvertVec3ToVec3BasedWrapper(const Vec3& input, TVec3BasedTypeWrapper& output)
		{
			output.value = input;
		}

		template <class TVec3BasedTypeWrapper>
		void ConvertVec3BasedWrapperToVec3(const TVec3BasedTypeWrapper& input, Vec3& output)
		{
			output = input.value;
		}
#endif

		void CStdLibRegistration::InstantiateItemFactoriesForRegistration()
		{
			// std::EntityId
			{
				Client::CItemFactory<EntityIdWrapper>::SCtorParams ctorParams;

				ctorParams.szName = "EntityId";
				ctorParams.guid = "1ad38a1e-1fd6-469e-a03a-4d600b334e62"_uqs_guid;
				ctorParams.callbacks.pAddItemToDebugRenderWorld = &EntityId_AddToDebugRenderWorld;
				ctorParams.callbacks.pCreateItemDebugProxy = &EntityId_CreateItemDebugProxyForItem;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "b53fd909-d454-4a5a-b125-3ca49cf7ffe5"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "4b8dbf98-d5eb-42bf-a3f4-ec288d71422b"_uqs_guid;
				ctorParams.callbacks.itemConverters.AddFromForeignTypeConverter<EntityId, &ConvertEntityIdToEntityIdWrapper>("EntityId", "std::EntityIdWrapper", "345ae48a-ad37-4458-94b9-64806c2df087"_uqs_guid);
				ctorParams.callbacks.itemConverters.AddToForeignTypeConverter<EntityId, &ConvertEntityIdWrapperToEntityId>("std::EntityIdWrapper", "EntityId", "82bd2238-dd8e-44ae-af30-a58e36f3b9a3"_uqs_guid);
#endif

				static const Client::CItemFactory<EntityIdWrapper> itemFactory_entityId(ctorParams);
			}

			// std::int
			{
				Client::CItemFactory<int>::SCtorParams ctorParams;

				ctorParams.szName = "std::int";
				ctorParams.guid = "da2d5ee0-ad34-4cfd-88bb-a4111701a648"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeItem<int>;
				ctorParams.callbacks.pCreateDefaultObject = &GetValueInitializedItem<int>;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "7c3ddebe-a1f0-452b-b1ff-11191b03b3b4"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "19a01e90-7cb8-4c1d-b8f7-208ebe3efb78"_uqs_guid;
#endif
				static const Client::CItemFactory<int> itemFactory_int(ctorParams);
			}

			// std::bool
			{
				Client::CItemFactory<bool>::SCtorParams ctorParams;

				ctorParams.szName = "std::bool";
				ctorParams.guid = "9605e7fe-d519-49e9-8ded-3e60170df1df"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeItem<bool>;
				ctorParams.callbacks.pCreateDefaultObject = &GetValueInitializedItem<bool>;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "ec49e7f2-57a1-4017-812c-d245ca289265"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "488692a5-ac8e-409c-a707-3141fca4c458"_uqs_guid;
#endif
				static const Client::CItemFactory<bool> itemFactory_bool(ctorParams);
			}

			// std::float
			{
				Client::CItemFactory<float>::SCtorParams ctorParams;

				ctorParams.szName = "std::float";
				ctorParams.guid = "73bcca90-c7c2-47be-94ac-6f306e82e257"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeItem<float>;
				ctorParams.callbacks.pCreateDefaultObject = &GetValueInitializedItem<float>;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "9737adf8-408b-43ed-9263-c6f33a2bd78e"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "3570e309-d6a9-4b9e-ae09-7616755eeca3"_uqs_guid;
#endif
				static const Client::CItemFactory<float> itemFactory_float(ctorParams);
			}

			// std::Pos3
			{
				Client::CItemFactory<Pos3>::SCtorParams ctorParams;

				ctorParams.szName = "std::Pos3";
				ctorParams.guid = "1b363d0a-dc71-45d4-9a8d-0fdb7d9e228c"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeTypeWrappedItem<Pos3>;
				ctorParams.callbacks.pCreateDefaultObject = &GetVec3BasedTypeWrapperZero<Pos3>;
				ctorParams.callbacks.pAddItemToDebugRenderWorld = &Pos3_AddToDebugRenderWorld;
				ctorParams.callbacks.pCreateItemDebugProxy = &Pos3_CreateItemDebugProxyForItem;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "1e11a732-a95f-4399-9c83-0198e2ec3262"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "3682383e-e146-4d0a-8917-2da8c0b34341"_uqs_guid;
				ctorParams.callbacks.itemConverters.AddFromForeignTypeConverter<Vec3, &ConvertVec3ToVec3BasedWrapper<Pos3>>("Vec3", "std::Pos3", "30aca024-1fff-4fb5-8956-cf54085c46dd"_uqs_guid);
				ctorParams.callbacks.itemConverters.AddToForeignTypeConverter<Vec3, &ConvertVec3BasedWrapperToVec3<Pos3>>("std::Pos3", "Vec3", "9c90027d-0a4e-4420-9069-8797e69d37bc"_uqs_guid);
#endif
				static const Client::CItemFactory<Pos3> itemFactory_Pos3(ctorParams);
			}

			// std::Ofs3
			{
				Client::CItemFactory<Ofs3>::SCtorParams ctorParams;

				ctorParams.szName = "std::Ofs3";
				ctorParams.guid = "41e2adc2-8318-43c4-b6f0-9bd549586dcf"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeTypeWrappedItem<Ofs3>;
				ctorParams.callbacks.pCreateDefaultObject = &GetVec3BasedTypeWrapperZero<Ofs3>;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "a20409f2-93bd-4a89-bc20-b99d87dc4a1d"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "9e01e609-3676-442e-a526-c3cd3f65a396"_uqs_guid;
				ctorParams.callbacks.itemConverters.AddFromForeignTypeConverter<Vec3, &ConvertVec3ToVec3BasedWrapper<Ofs3>>("Vec3", "std::Ofs3", "f36a4dde-2995-4f96-bda4-f8546b0074a9"_uqs_guid);
				ctorParams.callbacks.itemConverters.AddToForeignTypeConverter<Vec3, &ConvertVec3BasedWrapperToVec3<Ofs3>>("std::Ofs3", "Vec3", "5ff51b20-affa-4bf1-9bed-ec478a3c4f8c"_uqs_guid);
#endif
				static const Client::CItemFactory<Ofs3> itemFactory_Ofs3(ctorParams);
			}

			// std::Dir3
			{
				Client::CItemFactory<Dir3>::SCtorParams ctorParams;

				ctorParams.szName = "std::Dir3";
				ctorParams.guid = "eca80817-8631-48ba-9a1b-37d187ec92a2"_uqs_guid;
				ctorParams.callbacks.pSerialize = &Client::SerializeTypeWrappedItem<Dir3>;
				ctorParams.callbacks.pCreateDefaultObject = &GetVec3BasedTypeWrapperZero<Dir3>;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "1f78ca86-1627-41ad-990b-ca0f9dfc0879"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "e369872f-5c0f-4e38-9e99-106a25fe1f3e"_uqs_guid;
				ctorParams.callbacks.itemConverters.AddFromForeignTypeConverter<Vec3, &ConvertVec3ToVec3BasedWrapper<Dir3>>("Vec3", "std::Dir3", "95e16187-ac55-4dd7-80dd-0ffa42edbcdc"_uqs_guid);
				ctorParams.callbacks.itemConverters.AddToForeignTypeConverter<Vec3, &ConvertVec3BasedWrapperToVec3<Dir3>>("std::Dir3", "Vec3", "f525d01e-272e-4f38-a480-ab119d12b766"_uqs_guid);
#endif
				static const Client::CItemFactory<Dir3> itemFactory_Dir3(ctorParams);
			}

			// std::NavigationAgentTypeID
			{
				Client::CItemFactory<NavigationAgentTypeID>::SCtorParams ctorParams;

				ctorParams.szName = "std::NavigationAgentTypeID";
				ctorParams.guid = "4338dd81-718a-4365-a21a-65d5b5d08bd3"_uqs_guid;
				ctorParams.callbacks.pSerialize = &NavigationAgentTypeID_Serialize;
#if UQS_SCHEMATYC_SUPPORT
				ctorParams.guidForSchematycAddParamFunction = "cdb0111a-a042-41ca-9d4b-b52816a2ffa0"_uqs_guid;
				ctorParams.guidForSchematycGetItemFromResultSetFunction = "3d700e90-b5b6-47d2-bfb8-654458d462dc"_uqs_guid;
#endif
				static const Client::CItemFactory<NavigationAgentTypeID> itemFactory_NavigationAgentTypeID(ctorParams);
			}
		}

	}
}
