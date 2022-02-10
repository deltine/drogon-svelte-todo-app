import { serialize } from 'cookie';

export function makeSetCookie(params) {
	let serializes = [];
	for (const property in params) {
		if (params[property] == undefined) continue;
		serializes.push(
			serialize(property, params[property], {
				path: '/',
				httpOnly: true,
				sameSite: 'strict',
				secure: process.env.NODE_ENV === 'production',
				maxAge: 60 * 60 * 24 * 7 // one week
			})
		);
	}

	return {
		'Set-Cookie': serializes
	};
}

export function makeResetCoolie(params) {
	let serializes = [];
	console.log('params', params);
	for (const property in params) {
		console.log('params[property]', params[property]);
		serializes.push(
			serialize(params[property], '', {
				path: '/',
				expires: new Date(0),
				maxAge: 0
			})
		);
	}

	return {
		'Set-Cookie': serializes
	};
}

// import { serialize } from 'cookie';

// export function setCookie(key, value) {
//     return document.cookie = serialize(key, value, {
//         path: '/',
//         httpOnly: true,
//         sameSite: 'strict',
//         secure: process.env.NODE_ENV === 'production',
//         maxAge: 60 * 60 * 24 * 7, // one week
//     });
// };

// export function getCookie(name) {
// 	return document.cookie.split('; ').find(row => row.startsWith(name));
// };

// export function getCookieValue(name) {
// 	let cookiesPresent = getCookie(name);
// 	if (cookiesPresent) {
// 	  return cookiesPresent.split('=')[1];
// 	}
// 	return false;
// };
