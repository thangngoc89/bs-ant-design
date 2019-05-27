[@bs.module] external select: ReasonReact.reactClass = "antd/lib/select";

[%bs.raw {|require("antd/lib/select/style")|}];

[@bs.deriving jsConverter]
type size = [ | `small | `default | `large];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~showAction: array(string)=?,
    ~size: string=?,
    ~notFoundContent: ReasonReact.reactElement=?,
    ~transitionName: string=?,
    ~choiceTransitionName: string=?,
    ~showSearch: bool=?,
    ~allowClear: bool=?,
    ~disabled: bool=?,
    ~showArrow: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~tabIndex: int=?,
    ~placeholder: ReasonReact.reactElement=?,
    ~defaultActiveFirstOption: bool=?,
    ~dropdownClassName: string=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~dropdownMenuStyle: ReactDOMRe.Style.t=?,
    ~dropdownMatchSelectWidth: bool=?,
    ~onSearch: string => unit=?,
    /* ~getPopupContainer: ReasonReact.reactElement => HTMLElement=?, */
    /* ~filterOption: bool | ((inputValue: string, option: React.ReactElement<OptionProps>) => any)=?, */
    ~filterOption: bool=?,
    ~id: string=?,
    ~defaultOpen: bool=?,
    ~open_: bool=?,
    ~onDropdownVisibleChange: bool => unit=?,
    ~autoClearSearchValue: bool=?,
    /* ~dropdownRender: (menu?: ReasonReact.reactElement, props?: SelectProps) => ReasonReact.reactElement=?, */
    ~loading: bool=?,
    ~value: string=?,
    ~defaultValue: string=?,
    /* mode: 'default' | 'multiple' | 'tags' | 'combobox' |  */
    ~mode: string=?,
    ~optionLabelProp: string=?,
    ~firstActiveValue: array(string)=?,
    ~onChange: (
                 ~value: Js.t('a),
                 ~option: array(ReasonReact.reactElement)
               ) =>
               unit
                 =?,
    ~onSelect: (~value: Js.t('a), ~option: ReasonReact.reactElement) => unit
                 =?,
    ~onDeselect: (~value: Js.t('a)) => unit=?,
    ~onBlur: (~value: Js.t('a)) => unit=?,
    ~onFocus: unit => unit=?,
    ~onPopupScroll: ReactEvent.UI.t=?,
    ~onInputKeyDown: (~event: ReactEvent.Keyboard.t) => unit=?,
    ~onMouseEnter: (~event: ReactEvent.Mouse.t) => unit=?,
    ~onMouseLeave: (~event: ReactEvent.Mouse.t) => unit=?,
    ~maxTagCount: int=?,
    /* ~maxTagPlaceholder: ReasonReact.reactElement | ((omittedValues: T[]) => ReasonReact.reactElement)=?, */
    ~maxTagPlaceholder: ReasonReact.reactElement=?,
    ~optionFilterProp: string=?,
    ~labelInValue: bool=?,
    ~tokenSeparators: array(string)=?,
    ~getInputElement: unit => ReasonReact.reactElement=?,
    ~autoFocus: bool=?,
    ~suffixIcon: ReasonReact.reactElement=?,
    ~removeIcon: ReasonReact.reactElement=?,
    ~clearIcon: ReasonReact.reactElement=?,
    ~menuItemSelectedIcon: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";
let make =
    (
      ~prefixCls=?,
      ~className=?,
      ~showAction=?,
      ~size=?,
      ~notFoundContent=?,
      ~transitionName=?,
      ~choiceTransitionName=?,
      ~showSearch=?,
      ~allowClear=?,
      ~disabled=?,
      ~showArrow=?,
      ~style=?,
      ~tabIndex=?,
      ~placeholder=?,
      ~defaultActiveFirstOption=?,
      ~dropdownClassName=?,
      ~dropdownStyle=?,
      ~dropdownMenuStyle=?,
      ~dropdownMatchSelectWidth=?,
      ~onSearch=?,
      ~filterOption=?,
      ~id=?,
      ~defaultOpen=?,
      ~open_=?,
      ~onDropdownVisibleChange=?,
      ~autoClearSearchValue=?,
      ~loading=?,
      ~value=?,
      ~defaultValue=?,
      ~mode=?,
      ~optionLabelProp=?,
      ~firstActiveValue=?,
      ~onChange=?,
      ~onSelect=?,
      ~onDeselect=?,
      ~onBlur=?,
      ~onFocus=?,
      ~onPopupScroll=?,
      ~onInputKeyDown=?,
      ~onMouseEnter=?,
      ~onMouseLeave=?,
      ~maxTagCount=?,
      ~maxTagPlaceholder=?,
      ~optionFilterProp=?,
      ~labelInValue=?,
      ~tokenSeparators=?,
      ~getInputElement=?,
      ~autoFocus=?,
      ~suffixIcon=?,
      ~removeIcon=?,
      ~clearIcon=?,
      ~menuItemSelectedIcon=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=select,
    ~props=
      makeProps(
        ~prefixCls?,
        ~className?,
        ~showAction?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~notFoundContent?,
        ~transitionName?,
        ~choiceTransitionName?,
        ~showSearch?,
        ~allowClear?,
        ~disabled?,
        ~showArrow?,
        ~style?,
        ~tabIndex?,
        ~placeholder?,
        ~defaultActiveFirstOption?,
        ~dropdownClassName?,
        ~dropdownStyle?,
        ~dropdownMenuStyle?,
        ~dropdownMatchSelectWidth?,
        ~onSearch?,
        ~filterOption?,
        ~id?,
        ~defaultOpen?,
        ~open_?,
        ~onDropdownVisibleChange?,
        ~autoClearSearchValue?,
        ~loading?,
        ~value?,
        ~defaultValue?,
        ~mode?,
        ~optionLabelProp?,
        ~firstActiveValue?,
        ~onChange?,
        ~onSelect?,
        ~onDeselect?,
        ~onBlur?,
        ~onFocus?,
        ~onPopupScroll?,
        ~onInputKeyDown?,
        ~onMouseEnter?,
        ~onMouseLeave?,
        ~maxTagCount?,
        ~maxTagPlaceholder?,
        ~optionFilterProp?,
        ~labelInValue?,
        ~tokenSeparators?,
        ~getInputElement?,
        ~autoFocus?,
        ~suffixIcon?,
        ~removeIcon?,
        ~clearIcon?,
        ~menuItemSelectedIcon?,
        (),
      ),
    children,
  );

module Option = {
  [@bs.module "antd/lib/select"]
  external reactClass: ReasonReact.reactClass = "Option";

  [@bs.obj]
  external makeProps:
    (
      ~disabled: bool=?,
      ~value: string=?,
      ~title: string=?,
      ~children: ReasonReact.reactElement=?,
      ~className: string=?,
      ~key: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";

  let make =
      (
        ~disabled=?,
        ~value=?,
        ~title=?,
        ~children_inner=?,
        ~className=?,
        ~key=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~disabled?,
          ~value?,
          ~title?,
          ~children=?children_inner,
          ~className?,
          ~key?,
          ~style?,
          (),
        ),
      children,
    );
};