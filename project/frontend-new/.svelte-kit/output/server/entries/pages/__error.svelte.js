import { c as create_ssr_component } from "../../chunks/index-dbf0e059.js";
const load = async ({ status, error }) => {
  console.log(status);
  console.log(error);
  if (status === 404) {
    console.log("Is this not possible to redirect from here?");
    return { status: 302, redirect: "/" };
  }
  return { props: {} };
};
const _error = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `<h2 style="${"background-color: red"}">Error...</h2>

<a href="${"/login"}">Login</a>`;
});
export { _error as default, load };
