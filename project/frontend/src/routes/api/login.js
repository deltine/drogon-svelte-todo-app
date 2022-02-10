export const post = (request) => {
	// console.log("getSession request: ", request);
	// console.log("getSession request.locals: ", request.locals);
	const user = JSON.parse(request.body);
	console.log(user);

	return {
		user: {
			id: "testID",
			name: "testName",
			sccess: "admin" 
		}
	}
}