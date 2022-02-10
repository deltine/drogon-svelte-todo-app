import { c as create_ssr_component, a as createEventDispatcher, b as add_attribute, v as validate_component } from "../../chunks/index-dbf0e059.js";
import { N as Nav } from "../../chunks/nav-5cf152dc.js";
import { F as Footer } from "../../chunks/footer-88567eb4.js";
const LoginForm = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let mailAddress = "test@mail.jp";
  let password = "password";
  createEventDispatcher();
  return `<div class="${"#LoginForm max-w-xl mx-auto w-96 p-5 m-5 border-2 shadow-md"}"><div class="${"flex justify-between mt-6"}"><h2 class="${"text-3xl font-extrabold text-neutral-600"}">${`Sign in.`}</h2>
		<div class="${"items-center text-xl text-blue-600"}">
			<a href="${"javascript:void(0)"}">${`Sign up.`}</a></div></div>
	<div class="${"mt-8"}"><div class="${"mt-6"}"><div class="${"space-y-6"}"><div><label for="${"email"}" class="${"block text-sm font-medium text-neutral-600"}">Email address
					</label>
					<div class="${"mt-1"}"><input id="${"email"}" name="${"email"}" type="${"email"}" autocomplete="${"email"}" placeholder="${"Your Email"}" class="${"block w-full px-5 py-3 text-base text-neutral-600 placeholder-gray-300 transition duration-500 ease-in-out transform border 1 rounded-lg bg-sky-100 focus:outline-none focus:border-transparent focus:ring-2 focus:ring-white focus:ring-offset-2 focus:ring-offset-gray-300 "}"${add_attribute("value", mailAddress, 0)}></div></div>
				<div class="${"space-y-1"}"><label for="${"password"}" class="${"block text-sm font-medium text-neutral-600"}">Password
					</label>
					<div class="${"mt-1"}"><input id="${"password"}" name="${"password"}" type="${"password"}" autocomplete="${"current-password"}" placeholder="${"Your Password"}" class="${"block w-full px-5 py-3 text-base text-neutral-600 placeholder-gray-300 transition duration-500 ease-in-out transform border border-transparent rounded-lg bg-sky-100 focus:outline-none focus:border-transparent focus:ring-2 focus:ring-white focus:ring-offset-2 focus:ring-offset-gray-300 "}"${add_attribute("value", password, 0)}></div></div>
				<div class="${"flex items-center justify-between"}"><div class="${"flex items-center"}"><input id="${"remember-me"}" name="${"remember-me"}" type="${"checkbox"}" class="${"w-4 h-4 text-blue-600 border-gray-200 rounded focus:ring-blue-500 "}">
						<label for="${"remember-me"}" class="${"block ml-2 text-sm text-neutral-600"}">Remember me
						</label></div>
					<div class="${"text-sm"}"><a href="${"/"}" class="${"font-medium text-blue-600 hover:text-blue-500"}">Forgot your password?
						</a></div></div>
				<div><button type="${"submit"}" class="${"flex items-center justify-center w-full px-10 py-4 text-base font-medium text-center text-white transition duration-300 ease-in-out transform bg-blue-600 rounded-xl hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 backgroundcollo "}">${`Sign in.`}</button></div></div>
			<div class="${"relative my-4"}"><div class="${"absolute inset-0 flex items-center"}"><div class="${"w-full border-t border-gray-300"}"></div></div>
				<div class="${"relative flex justify-center text-sm"}"><span class="${"px-2 text-neutral-600 bg-white"}">Or continue with </span></div></div>
			<div><button type="${"submit"}" class="${"w-full items-center block px-10 py-3.5 text-base font-medium text-center text-blue-600 transition duration-500 ease-in-out transform border-2 border-white shadow-md rounded-xl focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-gray-500 "}"><div class="${"flex items-center justify-center"}"><svg xmlns="${"http://www.w3.org/2000/svg"}" xmlns:xlink="${"http://www.w3.org/1999/xlink"}" class="${"w-6 h-6"}" viewBox="${"0 0 48 48"}"><defs><path id="${"a"}" d="${"M44.5 20H24v8.5h11.8C34.7 33.9 30.1 37 24 37c-7.2 0-13-5.8-13-13s5.8-13 13-13c3.1 0 5.9 1.1 8.1 2.9l6.4-6.4C34.6 4.1 29.6 2 24 2 11.8 2 2 11.8 2 24s9.8 22 22 22c11 0 21-8 21-22 0-1.3-.2-2.7-.5-4z"}"></path></defs><clipPath id="${"b"}"><use xlink:href="${"#a"}" overflow="${"visible"}"></use></clipPath><path clip-path="${"url(#b)"}" fill="${"#FBBC05"}" d="${"M0 37V11l17 13z"}"></path><path clip-path="${"url(#b)"}" fill="${"#EA4335"}" d="${"M0 11l17 13 7-6.1L48 14V0H0z"}"></path><path clip-path="${"url(#b)"}" fill="${"#34A853"}" d="${"M0 37l30-23 7.9 1L48 0v48H0z"}"></path><path clip-path="${"url(#b)"}" fill="${"#4285F4"}" d="${"M48 48L17 24l-4-3 35-10z"}"></path></svg>
						<span class="${"ml-4"}">Log in with Google</span></div></button></div></div></div></div>`;
});
async function load({ session }) {
  console.log("index session", session);
  return { props: { session } };
}
const Routes = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `${$$result.head += `${$$result.title = `<title>Home</title>`, ""}`, ""}

<button type="${"submit"}">test </button>

<div class="${"#index"}"><div class="${"min-h-[640px] min-w-[980px]"}">${validate_component(Nav, "Nav").$$render($$result, {}, {}, {})}
		<div class="${"pt-[100px]"}"><div class="${"flex justify-center"}"><div class="${"flex items-center min-h-min-[300px]"}"><div class="${""}"><h1 class="${"text-4xl font-bold text-sky-800"}">SvelteKit Todo App</h1>
						<h2 class="${"text-2xl m-4"}">- frontend
							<p class="${"text-base"}">html / css / Javascript<br>
								Svelte / SvelteKit / Tailwind CSS
							</p>
							<br>

							- backend
							<p class="${"text-base"}">C++ / Drogon / MySql</p></h2></div></div>
				<div class="${"w-[490px] min-h-min-[300px]"}"><div class="${"justify-center overflow-hidden"}">${validate_component(LoginForm, "LoginForm").$$render($$result, {}, {}, {})}</div></div></div></div>
		${validate_component(Footer, "Footer").$$render($$result, {}, {}, {})}</div></div>`;
});
export { Routes as default, load };
